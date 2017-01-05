n = input()

for i in range(n):
    nome = raw_input()
    gd = input()
    arr = raw_input()
    v = list(map(float, arr.split()))
    v.sort()
    cont = 0.0
    for j in range(1,len(v)-1):
        cont+=v[j]
    print nome, "%.2f" % (cont*gd)
