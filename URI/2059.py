arr = raw_input()
p,j1,j2,r,a = map(int,arr.split())

if r and not a:
    print "Jogador 1 ganha!"
elif r and a:
    print "Jogador 2 ganha!"
elif not r and a:
    print "Jogador 1 ganha!"
elif (j1+j2)%2 == 0:
    if p:
        print "Jogador 1 ganha!"
    else:
        print "Jogador 2 ganha!"
else:
    if p:
        print "Jogador 2 ganha!"
    else:
        print "Jogador 1 ganha!"
    
