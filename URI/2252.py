import sys
teste = 1
while True:
    try:
        n = input()
    except EOFError:
        break
    sys.stdout.softspace=0
    print 'Caso ',
    sys.stdout.softspace=0
    print teste,
    sys.stdout.softspace=0
    print ':',
    teste+=1
    arr = raw_input()
    v = list(map(float,arr.split()))
    u = []
    for i in range(10):
       u.append((v[i],i))
    u.sort()
    for i in range(n):
        sys.stdout.softspace=0
        print u[i][1],
    sys.stdout.softspace=0
    print
