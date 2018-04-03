function [e] = errorFunction(K)
    assignin('base', 'K1', K(1));
    assignin('base', 'K2', K(2));
    assignin('base', 'K3', K(3));
    assignin('base', 'K4', K(4));
    assignin('base', 'K5', K(5));
    assignin('base', 'K6', K(6));
    
    sim('PendelModel_SIM.slx');
    e = ErrorSignal.signals(1);
    e = e.values(end);
end

