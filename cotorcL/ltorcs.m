function ltorcs()
	Omega = [0 0;0.2 -0.2;0.4 -0.4;0.6 -0.6;0.8 -0.8;1 -1;1.2 -1.2;1.4 -1.4;];
	W = [ 4 8 12 16 20 24];
	k = [ 1 2 3 4 5 6];
	l = [0 0;1 -1;2 -2;3 -3;4 -4;5 -5;6 -6;7 -7;];
	amp = [1 1 1 1 1 1 ];
	phase = [69 127 -3 -169 11 -7 ];
	ang = [4 8 12 16 20 24 ];
	freq = [1.4 1.4 1.4 1.4 1.4 1.4 ];
	jcreate_stim_profile(1, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-140 193 27 72 -35 92 ];
	ang = [4 8 12 16 20 24 ];
	freq = [1.2 1.2 1.2 1.2 1.2 1.2 ];
	jcreate_stim_profile(2, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [119 32 131 110 121 -60 ];
	ang = [4 8 12 16 20 24 ];
	freq = [1 1 1 1 1 1 ];
	jcreate_stim_profile(3, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [80 -26 99 -100 -16 10 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.8 0.8 0.8 0.8 0.8 0.8 ];
	jcreate_stim_profile(4, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [186 -29 -48 -94 -36 -157 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.6 0.6 0.6 0.6 0.6 0.6 ];
	jcreate_stim_profile(5, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [1 -150 247 -51 32 -52 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.4 0.4 0.4 0.4 0.4 0.4 ];
	jcreate_stim_profile(6, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-125 -154 -23 102 173 61 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.2 0.2 0.2 0.2 0.2 0.2 ];
	jcreate_stim_profile(7, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-136 112 -115 94 138 197 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0 0 0 0 0 0 ];
	jcreate_stim_profile(8, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [34 96 -4 -72 -132 14 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.2 -0.2 -0.2 -0.2 -0.2 -0.2 ];
	jcreate_stim_profile(9, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-58 -103 162 -24 62 105 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.4 -0.4 -0.4 -0.4 -0.4 -0.4 ];
	jcreate_stim_profile(10, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [64 196 -63 -59 -158 72 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.6 -0.6 -0.6 -0.6 -0.6 -0.6 ];
	jcreate_stim_profile(11, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-137 -98 -84 190 -8 140 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.8 -0.8 -0.8 -0.8 -0.8 -0.8 ];
	jcreate_stim_profile(12, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-220 -119 151 33 -102 -75 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-1 -1 -1 -1 -1 -1 ];
	jcreate_stim_profile(13, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [103 -57 7 -86 38 29 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-1.2 -1.2 -1.2 -1.2 -1.2 -1.2 ];
	jcreate_stim_profile(14, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [100 155 -25 -50 97 -17 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-1.4 -1.4 -1.4 -1.4 -1.4 -1.4 ];
	jcreate_stim_profile(15, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-111 -53 -183 -349 -169 -187 ];
	ang = [4 8 12 16 20 24 ];
	freq = [1.4 1.4 1.4 1.4 1.4 1.4 ];
	jcreate_stim_profile(16, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-320 13 -153 -108 -215 -88 ];
	ang = [4 8 12 16 20 24 ];
	freq = [1.2 1.2 1.2 1.2 1.2 1.2 ];
	jcreate_stim_profile(17, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-61 -148 -49 -70 -59 -240 ];
	ang = [4 8 12 16 20 24 ];
	freq = [1 1 1 1 1 1 ];
	jcreate_stim_profile(18, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-100 -206 -81 -280 -196 -170 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.8 0.8 0.8 0.8 0.8 0.8 ];
	jcreate_stim_profile(19, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [6 -209 -228 -274 -216 -337 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.6 0.6 0.6 0.6 0.6 0.6 ];
	jcreate_stim_profile(20, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-179 -330 67 -231 -148 -232 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.4 0.4 0.4 0.4 0.4 0.4 ];
	jcreate_stim_profile(21, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-305 -334 -203 -78 -7 -119 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0.2 0.2 0.2 0.2 0.2 0.2 ];
	jcreate_stim_profile(22, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-316 -68 -295 -86 -42 17 ];
	ang = [4 8 12 16 20 24 ];
	freq = [0 0 0 0 0 0 ];
	jcreate_stim_profile(23, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-146 -84 -184 -252 -312 -166 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.2 -0.2 -0.2 -0.2 -0.2 -0.2 ];
	jcreate_stim_profile(24, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-238 -283 -18 -204 -118 -75 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.4 -0.4 -0.4 -0.4 -0.4 -0.4 ];
	jcreate_stim_profile(25, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-116 16 -243 -239 -338 -108 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.6 -0.6 -0.6 -0.6 -0.6 -0.6 ];
	jcreate_stim_profile(26, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-317 -278 -264 10 -188 -40 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-0.8 -0.8 -0.8 -0.8 -0.8 -0.8 ];
	jcreate_stim_profile(27, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-400 -299 -29 -147 -282 -255 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-1 -1 -1 -1 -1 -1 ];
	jcreate_stim_profile(28, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-77 -237 -173 -266 -142 -151 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-1.2 -1.2 -1.2 -1.2 -1.2 -1.2 ];
	jcreate_stim_profile(29, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
	amp = [1 1 1 1 1 1 ];
	phase = [-80 -25 -205 -230 -83 -197 ];
	ang = [4 8 12 16 20 24 ];
	freq = [-1.4 -1.4 -1.4 -1.4 -1.4 -1.4 ];
	jcreate_stim_profile(30, amp, phase, ang, freq, 15, 13, k, l, W, Omega);
end

function ststims = jcreate_stim_profile(numrec, ampl, phsl, rates, scales, numcomp, leng, k, l, W, Omega)
	waveParams = zeros(2,length(k),length(l(:,1)),2);
	for cnum = 1:length(ampl)
		amp = ampl(cnum);
		phs = phsl(cnum);
		if amp < 0
			amp = abs(amp);
			phs = phs - 180;
		end
		temp = rates(cnum);
		ii = temp<0;
		veli = find(W==abs(temp));
		temp = scales(cnum);
		if ii
			temp = -temp;
			phs = -(phs+90)-90;
		end
		if temp
			[frqi,sgn]=find(Omega==temp);
		else
			frqi = 1;
			sgn = 1;
		end
		waveParams(:,veli,frqi,sgn) = [amp phs];
	end
	stimHolder = zeros(numcomp,leng);
	c = [floor(numcomp/2)+1,floor(leng/2)+1];
	count = 0;
	for row = 1:length(k)
		for sgn = 1:2
			for col = 1:size(l(:,1))
				count = count + 1;
				amp = waveParams(1,row,col,sgn);
				phs = waveParams(2,row,col,sgn);
				if amp
					stimHolder(c(1)+l(col,sgn),c(2)+k(row))= (amp/2)*exp(1i*(phs-90)*pi/180);
					stimHolder(c(1)-l(col,sgn),c(2)-k(row))= (amp/2)*exp(-1i*(phs-90)*pi/180);
				end
			end
		end
	end
	ststims = real(ifft2(ifftshift(stimHolder*(leng*numcomp))));
	scl = max(abs([min(min(ststims)),max(max(ststims))]));
	ststims = ststims*0.9/scl;
	f = fopen(sprintf('c1torc424l501%d_stimprof.txt',numrec), 'w');
	for ftorc = 1:15
		for ttorc = 1:13
			fprintf(f, '%g ', ststims(ftorc,ttorc));
		end
		fprintf(f, '\n');
	end
end