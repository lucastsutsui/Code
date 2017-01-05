teste = 1
while True:
    n = input()
    if n == 0:
        break
    print 'Teste', teste
    teste+=1
    j1 = raw_input()
    j2 = raw_input()
    for i in range(n):
        arr = raw_input()
        a,b = map(int, arr.split())
        if (a+b)%2 == 0:
            print j1
        else:
            print j2
    print
