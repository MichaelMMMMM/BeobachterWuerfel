% 18.02.18, MM JK

ParameterInit;

K = [K1, K2];

options = optimset('MaxFunEvals', 200);
[K, fval, exitflag, output] = fminsearch('errorFunction', K, options);

K1 = K(1);
K2 = K(2);