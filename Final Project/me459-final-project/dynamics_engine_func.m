function dynamics_engine_func(ankle_angle, hip_angle, iterations)
%% Segment Structure Definitions
% Lower segment defined as single rigid structure from ankle to hip
segment(1).l = 0.867;   %length of lower segment (ankle to hip) in [m]
segment(1).lc = 0.589;  %distance from ankle to center of mass of lower segment in [m]
segment(1).m = 26.30;   %mass of lower segment [kg]
segment(1).I = 1.400;   %Moment of inertia of lower segment around the ankle [kgm^2]
segment(1).Icm = segment(1).I + segment(1).m * segment(1).lc^2; %moment of inertia of lower segment around COM [kgm^2]
segment(1).g = 9.81;    % Acceleration due to gravity [m/s^2]
segment(1).t = 0;       %Torque around the ankle, to be populated later

% Upper segment defined as single structure from hip to top of head
segment(2).l = 0.851;   %length of upper segment in [m]
segment(2).lc = 0.332;  %distance from hip to COM of upper segment [m]
segment(2).m = 42.88;   %mass of upper segment [kg]
segment(2).I = 6.9534;  %Moment of inertia of upper segment around hip [kgm^2]
segment(2).Icm = segment(2).I + segment(2).m * segment(2).lc^2; %Moment of inertia of upper segment around COM [kgm^2]
segment(2).t = 0;       %Torque around the hip, to be populated later

%% Dynamic Value Structure Definitions
%Intial Conditions
init.phi1 = str2double(ankle_angle)*pi/180;   %Initial angular offset of the lower segment from vertical, in rad
init.phi1d = 0;         %Intial angular velocity of the lower segment around ankle, in rad/s
init.phi2 = str2double(hip_angle)*pi/180;   %Initial angular offset of the upper segment from lower segment, in rad
init.phi2d = 0;         %Initial angular velocity of the upper segment around the hip, in rad
init.t = 0;             %Initial time for each loop of the function
q0 = [init.phi1
    init.phi1d
    init.phi2
    init.phi2d];        %Array used to pass intial conditions into the ODE45 functions

%% Determine minimum torque at joints to keep system upright at start
torque = staticcheck(q0,segment);  %Identify torques for each joint needed to hold static equilibrium in the 
tankle = 3.5*torque(1);         %Setting initial value for ankle torque - factor based on observation to minimize wasted loops
tratio = .38;                   %Ratio used for initial hip torque, based on experimental observations/early iterations of this program
thip = tratio*tankle;           %Setting initial value for the hip torque

%% Intitialize looping parameters
j2 = 1;                         %Initialize counter for success loop 
loops = str2double(iterations);                    %Number of iterations of each torque to try
stableflag = zeros(loops);      %Initialize array to indicate where in looping success occured
precision = 0.1;                %Range around 0 degrees that both hip and ankle must pass simultaneously for "success"
time = zeros(loops*loops,4);    %initializes the array used for comparing execution speed of the two approaches
if tankle < 0
    torstep = 0.1;                  %Change in torque value for each iteration [Nm]
else
    torstep = -0.1;
end
    %% Execute Solution loops and check for satisfied criteria
for k1 = 1:loops                    %Loop to iterate across ankle torques
    tankle = tankle - torstep;      %Iterative step definition for ankle torque
    thip = tratio*tankle;
    for k2 = 1:loops                %Loop to iterate across hip torqes for one ankle torque
        thip = thip - torstep;      %Iterative step definition for hip torque
        segment(2).t = thip;        %Attach torque values to the segment structure to allow parameterization in ODE45
        segment(1).t = tankle;
        %% Approach 1 - Run ODE 45 and check result after full time range after each loop
        tspan = linspace(0,0.5,101); %Define the time range and number of steps for the solution of each torque combination
        opts = odeset('Mass',@(t1,q) mass(t1,q,segment));  %Update odeset for ODE45 to be able to process the Mass matrix
        tic                                                %Timer start for approach 1
        [t1,q] = ode45(@(t1,q) f(t1,q,segment),tspan,q0,opts);  %Call ODE45 to solve motion for given values
        phi1 = q(:,1).*180/pi;          %Convert output angular values from radians to degrees
        phi1dot = q(:,2).*180/pi;
        phi2 = q(:,3).*180/pi;
        phi2dot = q(:,4).*180/pi;
        for j=1:101                    
            %% Check if stable criteria is satisfied anywhere within the solution in first 0.5 seconds of motion
            if (precision >= phi1(j)) && (phi1(j) >= -precision) && (phi2(j) <= precision) && (phi2(j) >= -precision)
                stableflag(k1,k2) = 1;  %Output to matrix that provides visualization of where within the torque ranges success was found
                success(j2,1) = tankle; %Output to array capturing the parameters for a successful configuration
                success(j2,2) = thip;
                success(j2,3) = thip/tankle;
                success(j2,4) = j;
                j2 = j2+1;
                break
            end
        end
        time((k1-1)*loops+k2,1) = toc;  % Capture time for each iteration of the solver + stability validation process
        time((k1-1)*loops+k2,3) = j;
    end
end
%% Print Results of search
fprintf("Iterations: %4.0f\n",loops*loops)
fprintf("Average time for Method 1 loop execution: %1.4f sec \n",mean(time(:,1)));
fprintf("Total time for Method 1 loop execution: %1.4f sec \n",sum(time(:,1)));
if (exist('success','var') == 1)
    means = mean(success);
    summarytxt = ['For a starting ankle position of %2.2f degrees and starting hip position of %2.2f degrees, there were %.0f successful torque combinations in the range of \n' ...
        'Min Ankle torque %2.4f Nm and Max Ankle torque %2.4f Nm\n'...
        'Min Hip torque: %2.4f Nm and Max Hip torque: %2.4f Nm\n'];
    meantxt = ['Average ankle torque: %2.4f Nm \nAverage Hip Torque %2.4f Nm \n' ...
        'Average Ratio: %2.4f \nAverage time after start for intersect: %2.2f sec'];
    fprintf(summarytxt,init.phi1*180/pi,init.phi2*180/pi,size(success,1),torque(1),tankle,torque(2),thip);
    fprintf(meantxt,means(1),means(2), means(3), means(4)*.5/100);
    fileID = fopen('successes.txt','w');
    fprintf(fileID,"Ankle Start: %2.2f degrees.  Hip start: %2.2f degrees.\n",init.phi1*180/pi,init.phi2*180/pi);
    fprintf(fileID,"Number of successful configurations: %.0f\n",size(success,1));
    fprintf(fileID,'%12s | %12s\n','Ankle Torque','Hip Torque');
    fprintf(fileID,'%3.4f | %3.4f\n',success(:,1),success(:,2));
    fclose(fileID);
else
    failtxt = ['For a starting ankle position of %2.2f degrees and starting hip position of %2.2f degrees, there were no successful torque combinations. The range searched was from: \n' ...
        'Min Ankle torque %2.4f Nm to Max Ankle torque %2.4f Nm\n'...
        'Min Hip torque: %2.4f Nm to Max Hip torque: %2.4f Nm'];
    fprintf(failtxt,init.phi1*180/pi,init.phi2*180/pi,torque(1),tankle,torque(2),thip);
end

end
