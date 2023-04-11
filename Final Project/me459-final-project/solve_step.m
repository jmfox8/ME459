function out = solve_step(segment,in,t,step)
   q0 = [in(1)
    in(2)
    in(3)
    in(4)];

tspan = linspace(t,t+step,3);
opts = odeset('Mass',@(t,q) mass(t,q,segment));
[t,q] = ode45(@(t,q) f(t,q,segment),tspan,q0,opts);
out.phi1 = q(end,1)*180/pi;
out.phi1d = q(end,2)*180/pi;
out.phi2 = q(end,3)*180/pi;
out.phi2d = q(end,4)*180/pi;
out.t = t(end);

end
