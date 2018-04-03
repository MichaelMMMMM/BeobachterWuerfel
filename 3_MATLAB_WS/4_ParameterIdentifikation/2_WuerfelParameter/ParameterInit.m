% 18.02.18: MM, JK

ImportPhi;
ImportUK;

t = phi1.t; phi = phi1.phi; uk = uk1.uk;

t   = t(350:end)-t(350);
phi = phi(350:end);
uk  = uk(350:end);

phi_0 = phi(1);
uK_0  = uk(1);

sim_data = [t, phi];

l_AB = 0.084;
l_AC = 0.087;
mK   = 0.221;
mR   = 0.09;
OAK  = 2.8e-3;
Cphi = 6.2e-3;
g    = 9.81;
IK   = (OAK + l_AB*l_AB*mR);

K1   = (g * mK*l_AC+mR*l_AB)/IK;
K2   = Cphi/IK;

