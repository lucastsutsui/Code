t = int(input())

for asidosan in range(t):
    b = int(input())

    arr = raw_input()
    prim = list(map(int,arr.split()))
    arr = raw_input()
    sec = list(map(int,arr.split()))

    golpe1 = ((prim[0]+prim[1])/2.0)
    golpe2 = ((sec[0]+sec[1])/2.0)

    if prim[2]%2 == 0:
        golpe1 += b
    if sec[2]%2 == 0:
        golpe2 += b

    if golpe1 > golpe2:
        print "Dabriel"
    elif golpe2 > golpe1:
        print "Guarte"
    else:
        print "Empate"
