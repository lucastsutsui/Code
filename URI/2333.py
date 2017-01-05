n = input()
arr = raw_input()
v = list(map(int, arr.split()))
for i in range(n):
    v.append(v[i])

mx = 0
ini = 0
mx_s = 0
ini_s = 0
for i in range(len(v)):
    mx_s += v[i]
    if mx_s < 0 or i - ini_s >= n:
        mx_s = 0
        ini_s = i
    if mx_s > mx:
        mx = mx_s
        ini = ini_s
print mx
