while True:
    n = input()
    if n == 0:
        break
    arr = raw_input()
    v = list(map(int,arr.split()))

    flag = True
    for i in range(n):
        if v[v[i]-1] != i+1:
            flag = False

    if flag:
        print 'ambiguous'
    else:
        print 'not ambiguous'
