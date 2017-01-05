def numberOfSetBits(n):
  n = (n & 0x5555555555555555) + ((n & 0xAAAAAAAAAAAAAAAA) >> 1)
  n = (n & 0x3333333333333333) + ((n & 0xCCCCCCCCCCCCCCCC) >> 2)
  n = (n & 0x0F0F0F0F0F0F0F0F) + ((n & 0xF0F0F0F0F0F0F0F0) >> 4)
  n = (n & 0x00FF00FF00FF00FF) + ((n & 0xFF00FF00FF00FF00) >> 8)
  n = (n & 0x0000FFFF0000FFFF) + ((n & 0xFFFF0000FFFF0000) >> 16)
  n = (n & 0x00000000FFFFFFFF) + ((n & 0xFFFFFFFF00000000) >> 32) # This last & isn't strictly necessary.
  return n

t = int(input())

for koas in range(t):
    n = int(input())

    v = []
    for i in range(n):
        arr = raw_input()
        conj = list(map(int, arr.split()))
        c = 0
        for i in range(1,len(conj)):
            c |= (1<<conj[i])
        v.append(c)

    q = int(input())
    for i in range(q):
        arr = raw_input()
        conj = list(map(int,arr.split()))
        if conj[0] == 1:
            print numberOfSetBits(v[conj[1]-1] & v[conj[2]-1])
        else:
            print numberOfSetBits(v[conj[1]-1] | v[conj[2]-1])

            
