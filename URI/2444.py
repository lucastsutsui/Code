v,t = map(int,raw_input().split())
vv = list(map(int,raw_input().split()))
for k in vv:
    v += k
    if v > 100: v=100
    if v < 0: v=0
print v
