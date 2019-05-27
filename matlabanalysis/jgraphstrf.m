function jgraphstrf(fn)
    f = fopen(fn, 'r');
    if f == -1
        fprintf(1, 'Error opening strf %s\n', fn);
        return
    end
    data = fscanf(f, '%f');
    strf = reshape(data, [100 250]);
    strf = zeros(100,250);
    for i = 1:100
        strf(i,:) = data(250*(i-1)+1:250*(i-1)+250)';
    end
    %strf = 2*(strf - min(data))/(max(data) - min(data)) - 1;
    jstrf = strf./(1+exp(-(abs(strf)-0.9)/0.05));
    figure;
    %pcolor(jstrf);
    %imagesc(strf)
    %axis xy;
    noct = 5;
    lfreq = 500;%250;%500;
    leng = 13;
    basep = 250;
    clim = [-1, 1]*max(max(abs(strf)))
    %killnow();
    imagesc(1:250,0:0.01:noct,strf,clim);
    set(gca,'ytick',(0:noct));
    set(gca,'yticklabel',(lfreq*2.^[0:noct]/1000));
    set(gca,'xtick',(0:basep/5:basep));
    set(gca,'xticklabel',round(0:basep/5:basep));
    set(gca,'FontSize',30,'fontWeight','bold');
    %colormap(gca, 'jet');
    axis xy;
end