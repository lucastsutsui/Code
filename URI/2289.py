while True:
    arr = raw_input()
    x,y = map(long, arr.split())
    if x == 0 and y == 0:
        break
    x = x^y
    cont = 0
    while x != 0:
        if x&1:
            cont+=1
        x = x>>1
    print cont
