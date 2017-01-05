n = input()
arr = raw_input()

for sdsad in range(n):
    if sdsad != 0:
        print
        
    cont = 0
    d = dict()

    while True:
        try:
            arr = raw_input()
        except EOFError:
            break
        if arr == '':
            break
        if d.has_key(arr):
            d[arr]+=1
        else:
            d[arr] = 1
        cont+=1
    
    v = []
    for i in d:
        v.append(i)
    v.sort()
    
    for i in v:
        print i,
        print "%.4f" % (d[i]*100.0/float(cont))
        
