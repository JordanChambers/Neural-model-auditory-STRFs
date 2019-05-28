import string, sys

def generation_stats(fname):
    print fname
    f = open(fname, 'r')
    data = {}
    details = {}
    best = [100000,[]]
    top20 = []
    t20d = {}
    t20oa = {}
    blist = []
    g0ave = [0,0]
    print "Generation Number; [Average value of top 20, number of samples in top 20]"
    for line in f.readlines():
        info = string.split(line)
        if len(info) < 1:
            break
        gen = string.atoi(info[0])
        numb = string.atoi(info[1])
        if info[2] in ['-nan', 'nan']:
            info[2] = '1000000'
        val = string.atof(info[2])
        if gen == 0:
            g0ave[0] += val
            g0ave[1] += 1
        if gen not in data.keys():
            #print "gen"
            data[gen] = [0,0]
            details[gen] = {}
            t20d[gen] = []
            if gen >= 1:
                t20 = [0,0]
                for i in top20:
                    #print i, "%d; %d; %g" % (i[1][0], i[1][1], i[0])
                    t20[0] += i[0]
                    t20[1] += 1
                t20oa[gen-1] = t20[0]*1.0/t20[1]
                print gen-1, t20
                #killnow()
                blist.append(best[0])
        data[gen][0] += val
        data[gen][1] += 1
        if numb in details[gen].keys():
            numb += 1000
        details[gen][numb] = info[3:]
        if val < best[0]:
            best = [val, [gen, numb]]
        check = 1
        top20l = 20
        for i in top20:
            if details[gen][numb] == details[i[1][0]][i[1][1]]:
                check = 0
                #print "double", gen, numb, i
                #print details[gen][numb]
                #print details[i[1][0]][i[1][1]]
                #killnow()
                break
        if check == 1:
            if len(top20) < top20l:
                top20.append([val, [gen, numb]])
                top20.sort()
            else:
                if val < top20[top20l-1][0]:
                    top20.append([val, [gen, numb]])
                    top20.sort()
                    top20 = top20[:top20l]
        t20d[gen].append([val, [gen, numb]])
        if len(t20d[gen]) > 20:
            t20d[gen].sort()
            t20d[gen] = t20d[gen][:20]
    gk = data.keys()
    gk.sort()
    #print "Generation; count; average; top 20 average for this pop; top 20 average overall"
    for k in gk:
        t20 = [0,0]
        for i in t20d[k]:
            t20[0] += i[0]
            t20[1] += 1
        if k not in t20oa.keys():
            t20oa[k] = -1
        #print "%d; %d; %g; %g; %g" % (k, data[k][1], data[k][0]*1.0/data[k][1], t20[0]*1.0/t20[1], t20oa[k])
    #print "Best: %d; %d; %g; %s" % (best[1][0], best[1][1], best[0], details[best[1][0]][best[1][1]])
    st = '['
    for ji in details[best[1][0]][best[1][1]]:
        st += ' %s' % (ji)
    st += '];'
    print "Optimum solutions found: value, synaptic strengths"
    print best[0], st
    #print "Top20: Generation; numb; value"
    t20 = [0,0]
    for i in top20:
        #print "%d; %d; %g" % (i[1][0], i[1][1], i[0])
        t20[0] += i[0]
        t20[1] += 1
    #print "Top20 average: %g" % (t20[0]*1.0/t20[1])
    vnumb = len(details[best[1][0]][best[1][1]])
    topmean = []
    topvar = []
    jata = {}
    for j in range(vnumb):
        topmean.append(0)
        topvar.append(0)
        jata[j] = []
    topcnt = 0
    for i in top20:
        idt = details[i[1][0]][i[1][1]]
        for j in range(vnumb):
            topmean[j] += string.atoi(idt[j])
            jata[j].append(string.atoi(idt[j]))
        topcnt += 1
    for j in range(vnumb):
        topmean[j] = topmean[j]*1.0/topcnt
    for i in top20:
        idt = details[i[1][0]][i[1][1]]
        for j in range(vnumb):
            topvar[j] += pow((topmean[j] - string.atoi(idt[j])), 2)
    for j in range(vnumb):
        topvar[j] = pow(topvar[j]*1.0/topcnt, 0.5)
    #print "Variable", "Mean", "sd", "Taken from the best %d results" % (len(top20))
    st = "["
    for j in range(vnumb):
    #    print j, topmean[j], topvar[j], jata[j]
        st += " %d %d %g;" % (j, topmean[j], topvar[j])
    st += "]"
    #print st
    #print blist
    bls = 'gal%s = [' % (fname[:fname.index('.')])
    for i in blist:
        bls += ' %g' % (i)
    bls += '];'
    print "Optimum solutions for each generation:"
    print bls
    print g0ave[0]*1.0/g0ave[1]
    return

def run():
    fname = "reswasabi003a05.txt"
    if len(sys.argv) > 1:
        if '.' in sys.argv[1]:
            fname = sys.argv[1]
    generation_stats(fname)
    return

run()
