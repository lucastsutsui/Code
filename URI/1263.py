while True:
    try:
        arr = raw_input()
    except EOFError:
        break
    v = list(map(str, arr.split()))

    ans = v[0][0]
    ac = 0
    cont = 0
    for s in v:
        if s[0].upper() != ans.upper():
            ac = 1
            ans = s[0].upper()
        else:
            ac+=1
        if ac == 2:
            cont+=1
    print cont
