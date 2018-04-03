function [e] = errorFunction(K)
    assignin('base', 'K1', K(1));
    assignin('base', 'K2', K(2));
    
    sim('WuerfelPIModel_SIM');
    err = ErrorSignal.signals(1);
    e   = err.values(end);
end

