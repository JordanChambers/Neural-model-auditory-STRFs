import string, sys

def read_sen_file(fn):
    f = open(fn, 'r')
    data = {}
    for line in f.readlines():
        info = string.split(line)
        #if len(info) != 243:
        if len(info) != 258:
            continue
        numb = string.atoi(info[1])
        if numb in data.keys():
            print "Error with numb: already present"
            continue
        data[numb] = string.atof(info[2])
    return data

def run_sen_analysis():
    if len(sys.argv) != 4:
        print sys.argv
        print "Incorrect number of inputs"
        return
    base = string.atof(sys.argv[1])
    pfn = sys.argv[2]
    nfn = sys.argv[3]
    pdata = read_sen_file(pfn)
    ndata = read_sen_file(nfn)
    flist = []
    fabsl = []
    #for numb in range(240):
    for numb in range(255):
        if numb not in pdata.keys():
            print "%d not found in positive sen" % (numb)
            continue
        if numb not in ndata.keys():
            print "%d not found in negative sen" % (numb)
            continue
        if (pdata[numb] + 0.01) < base:
            print "%d pos is lower than best (%g compared to %g)" % (numb, pdata[numb], base)
        if (ndata[numb] + 0.01) < base:
            print "%d neg is lower than best (%g compared to %g)" % (numb, ndata[numb], base)
        value = 0.5*((pdata[numb] - base) + (ndata[numb] - base))
        flist.append(value)
        value = 0.5*(abs(pdata[numb] - base) + abs(ndata[numb] - base))
        fabsl.append(value)
    #print flist
    print fabsl
    return

run_sen_analysis()
