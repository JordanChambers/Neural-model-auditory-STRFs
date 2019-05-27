function dumpjANstmstorcs(jnumb)
    rng(jnumb);
    for fnumb = 1:1:30
        if fnumb < 10
            [jav, fs] = audioread(sprintf('../torcs/TORC_448_0%d_h501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_448_0%d_v501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_424_0%d_h501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_424_0%d_v501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_424_0%d_l501.wav', fnumb));
        else
            [jav, fs] = audioread(sprintf('../torcs/TORC_448_%d_h501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_448_%d_v501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_424_%d_h501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_424_%d_v501.wav', fnumb));
            %[jav, fs] = audioread(sprintf('../torcs/TORC_424_%d_l501.wav', fnumb));
        end
        fs
        length(jav)
        size(jav)
        njd = resample(jav, 5, 2);
        njd = njd*0.25;
        %figure;
        %plot(njd);
        jx = 0:5/14:5;
        %jx = 0:5/74:5;
        %jx = 0:5/44:5;
        franges = 250*2.^jx;
        %franges = franges(2:3:45);
        jtm = 3;
        for xnumb = 1:length(franges)
            xnumb, franges(xnumb)
            [meanrate, spiketms] = jANmodel(franges(xnumb), 100e3, jtm, njd', false);
            %figure;
            %plot(meanrate);
            %figure;
            %plot(spiketms);
            fout = fopen(sprintf('../cotorcH/cstmsc1torcH448_%d_%d_cat025s2_%d.txt', fnumb, jnumb, xnumb), 'w');
            for ii = 1:length(spiketms)
                if spiketms(ii) > 0
                    if spiketms(ii) > jtm
                        break
                    end
                    fprintf(fout, '%d %g\n', ii, spiketms(ii));
                else
                    break
                end
            end
            fclose(fout);
            fprintf(1, 'Completed %d %d\n', fnumb, xnumb);
        end
    end
end
