function [meanrate, vSpikeTimes] = jANmodel(CF, Fs, T, stim, disgraph)
    %CF    = 1.5e3;   % CF in Hz;   
    cohc  = 1.0;    % normal ohc function
    cihc  = 1.0;    % normal ihc function
    species = 1;    % 1 for cat (2 for human with Shera et al. tuning; 3 for human with Glasberg & Moore tuning)
    noiseType = 1;  % 1 for variable fGn (0 for fixed fGn)
    fiberType = 2;  % spontaneous rate (in spikes/s) of the fiber BEFORE refractory effects; "1" = Low; "2" = Medium; "3" = High
    implnt = 1;     % "0" for approximate or "1" for actual implementation of the power-law functions in the Synapse

    % stimulus parameters
    %Fs = 100e3;  % sampling rate in Hz (must be 100, 200 or 500 kHz)
    %T  = 5;%50e-3;  % stimulus duration in seconds
    rt = 2.5e-3; % rise/fall time in seconds

    % PSTH parameters
    nrep = 1;               % number of stimulus repetitions (e.g., 50);
    psthbinwidth = 0.5e-3; % binwidth in seconds;


    vihc = model_IHC(stim,CF,nrep,1/Fs,T*2,cohc,cihc,species); 
    [meanrate,varrate,psth,vSpikeTimes] = model_Synapse(vihc,CF,nrep,1/Fs,fiberType,noiseType,implnt);
    timeout = (1:length(psth))*1/Fs;
    %vSpikeTimes
    psthbins = round(psthbinwidth*Fs);  % number of psth bins per psth bin
    psthtime = timeout(1:psthbins:end); % time vector for psth
    pr = sum(reshape(psth,psthbins,length(psth)/psthbins))/nrep; % pr of spike in each bin
    Psth = pr/psthbinwidth; % psth in units of spikes/s
%     length(meanrate), length(varrate), length(psth)
%   figure;
%    subplot(2,1,1)
%    plot(timeout,meanrate); 
%    xl = xlim;
%    title('Mean Rate Output')
%    xlabel('Time (s)')
% 
%     subplot(2,1,2)
%     bar(psthtime,Psth)
%     xlim(xl)
%     title('psth')
%     xlabel('Time (s)')
%     
% 
%     %vSpikeTimes = 0.1 + vSpikeTimes;
    if disgraph
        figure
        subplot(4,1,1)
        plot(timeout,[stim zeros(1,length(timeout)-length(stim))])
        title('Input Stimulus')

        subplot(4,1,2)
        plot(timeout,vihc(1:length(timeout)))
        title('IHC output')

        subplot(4,1,3)
        plot(timeout,meanrate); 
        xl = xlim;
        title('Mean Rate Output')
        xlabel('Time (s)')

        subplot(4,1,4)
        bar(psthtime,Psth)
        xlim(xl)
        title('psth')
        xlabel('Time (s)')
        
        figure;
        bar(psthtime, Psth)
        title('psth')
        xlabel('Time (s)')
    end
end