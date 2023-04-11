%% Function to determine minium torques needed to hold system upright
function Tmin = staticcheck(q,P)

    seg1_l = P(1).l;
    seg1_lc = P(1).lc;
    seg1_m = P(1).m;
    seg1_I = P(1).I;
    seg1_ICM = P(1).Icm;
    g = P(1).g;
    seg2_l = P(2).l;
    seg2_lc = P(2).lc;
    seg2_m = P(2).m;
    seg2_I = P(2).I;
    seg2_ICM = P(2).Icm;
    
    Tmin(1) = -g*(seg1_m*seg1_lc*sin(q(1)) + seg2_m*(seg1_l*sin(q(1)) + seg2_lc*sin(q(1)+q(3))));
    Tmin(2) = -g*(seg2_m*seg2_lc*sin(q(1)+q(3)));
end
    