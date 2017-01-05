arr = raw_input()
n,m = map(int,arr.split())
arr = raw_input()
v = list(map(int, arr.split()))
v.append(42195)

flag = True
for i in range(n):
    if v[i+1]-v[i] > m:
        flag = False
if flag:
    print 'S'
else:
    print 'N'
