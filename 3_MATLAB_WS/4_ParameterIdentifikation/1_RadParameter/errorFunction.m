function [e] = errorFunction(K)
    assignin('base', 'IR', K(1));
    assignin('base', 'Cpsi', K(2));
    
    sim('MotorParameterIdentification_SIM.slx');
    err = errorSignal.signals(1);
    e = err.values(end);
end

