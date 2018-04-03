% 18.02.18, MM, JK

% Paramter-Berechnung aus Identifikation und Messdaten

load('WuerfelParameter.mat');

mG = 0.98;      %Masse Wuerfel + Achse mittels Waage bestimmt
p_Stahl  = 7900;
r_Stange = 0.004;
l_Stange = 0.252;
V_Stange = pi*r_Stange*r_Stange*l_Stange;
m_Stange = p_Stahl*V_Stange;
m = mG-m_Stange;
g = 9.81;
T = 2.47-1.21;
