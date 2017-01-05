x = input()
v = dict()

for i in range(x):
    arr = raw_input()
    n,p1,p2,p3 = map(str, arr.split(' '))
    v[n] = (p1,p2,p3)

while True:
    try:
        arr = raw_input()
    except:
        break

    n1,p = map(str, arr.split(' '))
    if v.has_key(n1) and p in v[n1]:
        print "Uhul! Seu amigo secreto vai adorar o/"
    else:
        print "Tente Novamente!"
    
