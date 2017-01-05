arr = raw_input()
n,c,s = map(int, arr.split())

arr = raw_input()
cmd = list(map(int, arr.split()))

curr = 0
cont = 0

if curr == s-1:
    cont+=1

for i in cmd:
    curr += i

    if curr < 0:
        curr = n-1
    elif curr >= n:
        curr = 0

    if curr == s-1:
        cont+=1
        
print cont
