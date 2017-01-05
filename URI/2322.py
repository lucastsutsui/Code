n = input()
arr = raw_input()
v = list(map(int, arr.split()))
ta = []
for i in range(n):
    ta.append(False)
for i in range(n-1):
    ta[v[i]-1] = True
for i in range(n):
    if not ta[i]:
        print i+1
        break
