v = [False for i in range(100)]
ap = list(map(int,raw_input().split()))
st = list(map(int,raw_input().split()))
for k in ap: v[k] = True
cont=0
for k in st:
    if v[k]: cont+=1
if cont == 3: print "terno"
elif cont == 4: print "quadra"
elif cont == 5: print "quina"
elif cont == 6: print "sena"
else: print "azar"
