while True:
    try:
        n = input()
    except EOFError:
        break
    arr = raw_input()
    v = map(int,arr.split())
    total = 0
    for i in v:
        total += i
    nova = total/n
    res = 0
    for i in v:
        res += abs(nova-i)
    if total%n==0:
        print 1+res/2
    else:
        print -1
