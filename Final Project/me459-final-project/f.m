%% EOM Function Definitions - Right Hand Side
function pdot = f(t,q,P)
    % Extract system values from segment structures
    seg1_l = P(1).l;
    seg1_lc = P(1).lc;
    seg1_m = P(1).m;
    seg1_I = P(1).I;
    seg1_ICM = P(1).Icm;
    seg1_t = P(1).t;
    g = P(1).g;
    
    seg2_l = P(2).l;
    seg2_lc = P(2).lc;
    seg2_m = P(2).m;
    seg2_I = P(2).I;
    seg2_ICM = P(2).Icm;
    seg2_t = P(2).t;

    % Define dynamic matrix and gravity matrix terms
    C = zeros(2,2);
    C(1,1) = -2*q(4);
    C(1,2) = -q(4);
    C(2,1) = q(2);
   
    G(1,:) = seg1_m*seg1_lc*sin(q(1)) + seg2_m*(seg1_l*sin(q(1)) + seg2_lc*sin(q(1)+q(3)));
    G(2,:) = seg2_m*seg2_lc*sin(q(1)+q(3));
    
    %combine for total non-inertial terms
    pdot(1,:) = q(2);
    pdot(2,:) = -seg2_m*seg1_l*seg2_lc*sin(q(3))*(C(1,1)*q(2)+C(1,2)*q(4)) + g*G(1) + seg1_t;
    pdot(3,:) = q(4);
    pdot(4,:) = -seg2_m*seg1_l*seg2_lc*sin(q(3))*(C(2,1)*q(2)+C(2,2)*q(4)) + g*G(2) + seg2_t;

    end
