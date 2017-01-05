n = input()
arr = raw_input()
v = list(map(int, arr.split()))

totalV = 0
totalC = 0
vis = []
roub = 0

for i in range(n):
    totalC += v[i]
    vis.append(False)

curr = 0
while True:
    if not vis[curr]:
        roub += 1
        vis[curr] = True
    if v[curr] > 0:
        totalV += 1
    
    if v[curr]%2 == 1:
        if v[curr] > 0:
            v[curr] -= 1
        curr += 1
    else:
        if v[curr] > 0:
            v[curr] -= 1
        curr -= 1
        
    if curr < 0 or curr >= n:
        break

print roub, totalC-totalV
