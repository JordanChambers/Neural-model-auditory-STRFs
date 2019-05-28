import string, sys

def generation_stats(fname):
    print fname
    f = open(fname, 'r')
    top20 = [[100000000,'']]
    for line in f.readlines():
        info = string.split(line)
        if len(info) < 1:
            break
        gen = string.atoi(info[0])
        numb = string.atoi(info[1])
        if info[2] in ['-nan', 'nan']:
            info[2] = '1000000'
        val = string.atof(info[2])
        if val < top20[-1][0]:
            top20.append([val, line])
            if len(top20) > 20:
                top20.sort()
                del top20[-1]
    f.close()
    f = open(fname, 'w')
    for top in top20:
        f.write("%s\n" % (top[1]))
    f.close()
    return

def run():
    flist = ["dai003b-d2act02.txt", "dai003b-d2act03.txt", "dai003b-d2act04.txt", "dai003b-d2act05.txt", "dai003b-d2act06.txt", "dai003b-d2pas01.txt", "dai003b-d2pas02.txt", "dai003b-d2pas03.txt", "dai003b-d2pas04.txt", "dai003b-d2pas05.txt", "dai003b-d2pas06.txt", "dai004c-a1act01.txt", "dai004c-a1act02.txt", "dai004c-a1act03.txt", "dai004c-a1act04.txt", "dai004c-a1act05.txt", "dai004c-a1act06.txt", "dai004c-a1pas02.txt", "dai004c-a1pas03.txt", "dai004c-a1pas04.txt", "dai004c-a1pas05.txt", "dai004c-a1pas06.txt", "dai010a-d1act01.txt", "dai006a-c1act02.txt", "dai006a-c1act03.txt", "dai006a-c1act04.txt", "dai006a-c1act05.txt", "dai006a-c1act06.txt", "dai006a-c1pas02.txt", "dai006a-c1pas03.txt", "dai006a-c1pas05.txt", "dai006a-c1pas06.txt", "dai008b-c1act02.txt", "dai008b-c1act03.txt", "dai008b-c1act04.txt", "dai008b-c1act05.txt", "dai008b-c1act06.txt", "dai008b-c1pas02.txt", "dai008b-c1pas03.txt", "dai008b-c1pas05.txt", "dai008b-c1pas06.txt", "dai009a-c2act01.txt", "dai009a-c2act02.txt", "dai009a-c2act03.txt", "dai009a-c2act04.txt", "dai009a-c2act05.txt", "dai009a-c2act06.txt", "dai009a-c2pas01.txt", "dai009a-c2pas02.txt", "dai009a-c2pas03.txt", "dai009a-c2pas04.txt", "dai009a-c2pas05.txt", "dai009a-c2pas06.txt", "dai010a-d1act02.txt", "dai010a-d1act03.txt", "dai010a-d1act04.txt", "dai010a-d1act05.txt", "dai010a-d1act06.txt", "dai010a-d1pas01.txt", "dai010a-d1pas02.txt", "dai010a-d1pas03.txt", "dai010a-d1pas04.txt", "dai010a-d1pas05.txt", "dai010a-d1pas06.txt", "tel007a-g1act01.txt", "tel007a-g1act02.txt", "tel007a-g1act03.txt", "tel007a-g1act04.txt", "tel007a-g1act05.txt", "tel007a-g1act06.txt", "tel007a-g1pas02.txt", "tel007a-g1pas03.txt", "tel007a-g1pas04.txt", "tel007a-g1pas05.txt", "tel007a-g1pas06.txt", "tel007a-h1act02.txt", "tel007a-h1act03.txt", "tel007a-h1act04.txt", "tel007a-h1act05.txt", "tel007a-h1act06.txt", "tel007a-h1pas02.txt", "tel007a-h1pas03.txt", "tel007a-h1pas04.txt", "tel007a-h1pas05.txt", "tel007a-h1pas06.txt", "dai006a-c1pas04.txt"]
    for fname in flist:
        generation_stats(fname)
    return

run()
