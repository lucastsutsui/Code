media = 0
n = 0
while True:
    arr = raw_input()
    w1,w2,r = map(int,arr.split())
    if w1==0 and w2==0 and r==0:
        break
    m = w1*(1.0 + (r/30.0)) + w2*(1.0+(r/30.0))
    m /= 2.0

    if m < 13.0:
        print 'Nao vai da nao'
    elif m < 14.0:
        print 'E 13'
    elif m < 40.0:
        print 'Bora, hora do show! BIIR!'
    elif m <= 60.0:
        print 'Ta saindo da jaula o monstro!'
    else:
        print 'AQUI E BODYBUILDER!!'
    media += m
    n+=1
if media/float(n) >= 40.0:
    print
    print 'Aqui nois constroi fibra rapaz! Nao e agua com musculo!'
