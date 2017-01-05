n = input()
v = []
for i in range(n):
    arr = raw_input()
    l = list(map(int, arr.split()))
    v.append(l)
flag = False
cont = 0
# LINHAS
for i in range(n):
    cont2 = 0
    for j in range(n):
        cont2 += v[i][j]
    if flag and cont != cont2:
        cont = -1
    elif not flag:
        cont = cont2
        flag = True
# COLUNAS
for i in range(n):
    cont2 = 0
    for j in range(n):
        cont2 += v[j][i]
    if cont != cont2:
        cont = -1
# DIAGONAL PRINCIPAL
cont2 = 0
for i in range(n):
    cont2 += v[i][i]
if cont != cont2:
    cont = -1
# DIAGONAL SECUNDARIA
cont2 = 0
for i in range(n):
    cont2 += v[i][n-1-i]
if cont != cont2:
    cont = -1
    
print cont
