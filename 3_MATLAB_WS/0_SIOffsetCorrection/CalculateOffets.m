% Michael Meindl, 17.02.18
% Berechnung der Offets/Systematischen Messabweichungen von Phi, uK und uR.
% Benutzt werden die Messdaten über 50 Sekunden, wobei der Würfel nach
% unten hängt. In dieser stabilen Ruhelage sind alle Zustandsgrößen Null,
% weshalb der verbleibende Anzeigewert der Messabweichung entspricht.

clear; 
close all;

% Import the datafiles
ImportPhi;
ImportUK;
ImportUR;

t = phi.t; phi = phi.phi; uk = uk.uk; ur = ur.ur;

phi_offset = mean(phi);
uk_offset  = mean(uk);
ur_offset  = mean(ur);

% Plot the data
emlFigure;
plot(t, phi, t, ones(size(phi))*phi_offset); grid; 
emlXLabel('Zeit in Sekunden'); emlYLabel('$\varphi$ in Radiant');
emlLegend({'$\varphi$', '$\overline{\varphi}$'});

emlFigure;
plot(t, uk, t, ones(size(uk))*uk_offset); grid; 
emlXLabel('Zeit in Sekunden'); emlYLabel('$u_K$ in Radiant pro Sekunde');
emlLegend({'$u_K$', '$\overline{u}_K$'});

emlFigure;
plot(t, ur, t, ones(size(ur))*ur_offset); grid; 
emlXLabel('Zeit in Sekunden'); emlYLabel('$u_R$ in Radiant pro Sekunde');
emlLegend({'$u_R$', '$\overline{u}_R$'});

csvwrite('sysident_offsets.csv', [phi_offset; uk_offset; ur_offset]);