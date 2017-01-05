n = input()

suc = [0,0,0]
tot = [0,0,0]

for i in range(n):
    arr = raw_input()
    arr = raw_input()
    s,b,a = map(int, arr.split())
    tot[0] += s
    tot[1] += b
    tot[2] += a
    arr = raw_input()
    s,b,a = map(int, arr.split())
    suc[0] += s
    suc[1] += b
    suc[2] += a

print 'Pontos de Saque:', "%.2f" % (suc[0]*100.0/float(tot[0])), '%.'
print 'Pontos de Bloqueio:', "%.2f" % (suc[1]*100.0/float(tot[1])), '%.'
print 'Pontos de Ataque:', "%.2f" % (suc[2]*100.0/float(tot[2])), '%.'
