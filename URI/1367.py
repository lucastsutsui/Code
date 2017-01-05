while True:
    n = input()
    if n == 0:
        break

    v = []
    for i in range(ord('Z')-ord('A')+1):
        v.append(0)

    for i in range(n):
        arr = raw_input()
        p,t,j = map(str, arr.split())

        if j == 'incorrect':
            v[ord(p)-ord('A')]-=1
        elif v[ord(p)-ord('A')] <= 0:
            if v[ord(p)-ord('A')] != 0:
                v[ord(p)-ord('A')] = -v[ord(p)-ord('A')]*20
            v[ord(p)-ord('A')] += int(t)

    prob = 0
    tempo = 0
    for i in range(ord('Z')-ord('A')+1):
        if v[i] > 0:
            prob+=1
            tempo+=v[i]

    print prob, tempo
