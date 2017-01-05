while True:
    try:
        s = raw_input()
        p = int(raw_input())
    except EOFError:
        break

    cont = 0
    c2 = 0
    flag = False
    for x in s:
        if x == 'R':
            if flag == False:
                cont+=1
                c2 = 0
            flag = True
            if c2 == p:
                c2 = 1
                cont+=1
            else:
                c2+=1
        else:
            flag = False
            cont+=1
    print cont
