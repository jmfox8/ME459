%% EOM Function Definitions - Inertial Matrix
function M = mass(t,q,P)
    % Extract system values from segment structures
    seg1_l = P(1).l;
    seg1_lc = P(1).lc;
    seg1_m = P(1).m;
    seg1_I = P(1).I;
    seg1_ICM = P(1).Icm;
    
    seg2_l = P(2).l;
    seg2_lc = P(2).lc;
    seg2_m = P(2).m;
    seg2_I = P(2).I;
    seg2_ICM = P(2).Icm;
    
    % Define inertial matrix term
    inert = zeros(2);
    inert(1,1) = seg1_ICM + seg2_ICM + seg2_m*(seg1_l^2+seg1_l*seg2_lc*cos(q(3)));
    inert(1,2) = seg2_ICM + seg2_m*seg1_l*seg2_lc*cos(q(3));
    inert(2,1) = seg2_ICM + seg2_m*seg2_lc*seg1_l*cos(q(3));
    inert(2,2) = seg2_ICM;

    M = zeros(4);
    M(1,1) = 1;
    M(2,2) = inert(1,1);
    M(2,4) = inert(1,2);
    M(3,3) = 1;
    M(4,2) = inert(2,1);
    M(4,4) = inert(2,2);

end