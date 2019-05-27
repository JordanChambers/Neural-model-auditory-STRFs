import sys, string

f = open('jamsyn.c', 'w')
f.write("void jam_syns(void)\n{\n")

count = 0
for i in sys.argv[1:]:
    for j in [',', '[', ']']:
        if j in i:
            i = string.replace(i, j, '')
    #print "jata.jga.cpop[jata.jga.id][%d] = %s;" % (count, i)
    f.write("jata.jga.cpop[jata.jga.id][%d] = %s;\n" % (count, i))
    count += 1
f.write("}\n");
f.close()
