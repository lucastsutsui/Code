while True:
    try:
        arr = raw_input()
    except EOFError:
        break
    v = [0,0,0,0,0,0,0,0,0,0]
    for i in arr:
        v[int(i)]+=1
    mx = 0
    for i in range(10):
        if v[i] >= v[mx]:
            mx = i
    print mx
