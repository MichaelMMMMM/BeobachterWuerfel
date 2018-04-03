% 18.02.18: MM, JK

clear; close all;

Cpsi = 3e-5;
IR   = 1.2e-4;

ImportTM;
ImportUR;

t = tm.t; tm = tm.tm; ur = ur.ur;

uR_0 = ur(1);

sim_data = [t, ur, tm];