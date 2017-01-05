while True:
    arr = raw_input()
    n,b = map(int, arr.split())
    if n==0 and b==0:
        break
    arr = raw_input()
    v = list(map(int, arr.split()))

    ta = []
    for i in range(n+1):
        ta.append(False)

    for i in range(len(v)-1):
        for j in range(i,len(v)):
            #print abs(v[i]-v[j])
            ta[abs(v[i]-v[j])] = True

    flag = True
    for i in range(n+1):
        if ta[i] == False:
            flag = False
    
    if flag:
        print 'Y'
    else:
        print 'N'
