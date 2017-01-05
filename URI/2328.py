n = input()
arr = raw_input()
v = list(map(int,arr.split()))

cont = 0
for i in range(n):
    cont += v[i]-1
print cont
