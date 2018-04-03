% 17.02.18: Michael Meindl, Jannick Küster
%
% Initialisierung der Systemparameter

l_AB = 0.084;
l_AC = 0.087;
mK   = 0.221;
mR   = 0.09;
OAK  = 2.8e-3;
OBR  = 1.1683e-4;
Cphi = 6.2e-3;
Cpsi = 3.1176e-5;
g    = 9.81;

IK   = (OAK + l_AB*l_AB*mR)*1.6;
IR   = OBR;

K1   = (g * mK*l_AC+mR*l_AB)/IK;
K2   = (Cphi + Cpsi)/IK;
K3   = Cpsi/IK;
K4   = 1/IK;
K5   = Cpsi/IR;
K6   = 1/IR;

ImportPhi;
ImportUK;
ImportUR;
ImportTM;

t = phi1.t; phi = phi1.phi; uk = uk1.uk; ur = ur1.ur; tm = tm1.tm;

phi_0 = phi(4000);
uK_0  = uk(4000);
uR_0  = ur(4000);

%sim_data = [t(4000:5000)-t(4000), phi(4000:5000), uk(4000:5000), ur(4000:5000), tm(4000:5000)];

sim_data = [t, phi, uk, ur, tm];
phi_0    = phi(1);
uK_0     = uk(1);
uR_0     = ur(1);

phi_max = max(abs(phi));
uk_max  = max(abs(uk));
ur_max  = max(abs(ur));

Q       = diag([1/(phi_max*phi_max), 1/(uk_max*uk_max), 1/(ur_max*ur_max)]);

A = [0, 1, 0; -K1, -K2, K3; 0, K5, -K5]; B = [0; -K4; K6];
C = [1, 0, 0]; D = 0;

zrd = ss(A, B, C, D);