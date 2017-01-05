import sys

n = input()

for asda in range(n):
    arr = raw_input()
    p,c = map(str, arr.split())
    c = int(c)

    num = 0
    for i in range(len(p)):
        if p[i] == 'X':
            num |= (1<<i)
            
    num -= c
    
    for i in range(len(p)):
        if num%2 == 0:
            sys.stdout.softspace = 0
            print 'O',
        else:
            sys.stdout.softspace = 0
            print 'X',
        num /= 2
    sys.stdout.softspace = 0
    print
            
