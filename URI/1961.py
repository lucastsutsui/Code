arr = raw_input()
p,n = map(int,arr.split())
arr = raw_input()
v = list(map(int,arr.split()))

ans = v[0]
flag = True
for i in range(1,n):
    if abs(ans-v[i]) > p:
        flag = False
    ans = v[i]

if flag:
    print 'YOU WIN'
else:
    print 'GAME OVER'
