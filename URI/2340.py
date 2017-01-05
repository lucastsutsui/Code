import math
n = input()
mx = 0
im = -1
for i in range(n):
    arr = raw_input()
    d,c = map(int, arr.split())
    if mx < float(c*math.log(d)) or im == -1:
        im = i
        mx = float(c)*math.log(d)
print im
