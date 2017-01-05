import sys

while True:
    n = input()
    if n == 0:
        break
    i = 1
    while i*i <= n:
        if i == 1:
            sys.stdout.softspace=0
            print i*i,
        else:
            sys.stdout.softspace=0
            print ' ',
            sys.stdout.softspace=0
            print i*i,
        i+=1
    sys.stdout.softspace=0
    print
