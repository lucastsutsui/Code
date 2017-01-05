arr=raw_input()
n,m = map(int,arr.split())
v = []
for i in range(n):
    arr = raw_input()
    v.append(list(map(int,arr.split())))

mx = 0
for i in range(n):
    c = 0
    for j in range(m):
        c += v[i][j]
    if c > mx:
        mx = c

for i in range(m):
    c = 0
    for j in range(n):
        c += v[j][i]
    if c > mx:
        mx = c
print mx
