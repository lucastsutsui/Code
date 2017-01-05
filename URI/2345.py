arr = raw_input()
v = list(map(int,arr.split()))
v.sort()
print abs(v[3]+v[0]-v[1]-v[2])
