n = input()
mal = 0
bem = 0
v = []
for i in range(n):
    arr = raw_input()
    op,nome = map(str, arr.split())
    if op == '+':
        bem+=1
    else:
        mal+=1
    v.append(nome)
v.sort()
for s in v:
    print s
print "Se comportaram: " + str(bem) +" | Nao se comportaram: " + str(mal)
