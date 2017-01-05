arr = raw_input()
d1,m1 = map(int, arr.split())
arr = raw_input()
d2,m2 = map(int, arr.split())

v = [0,31,28,31,30,31,30,31,31,30,31,30,31]
cont = 0
for i in range(13):
    ans = v[i]
    v[i] += cont
    cont += ans

print (v[m2-1]+d2)-(v[m1-1]+d1)
