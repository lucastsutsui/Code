n = input()

arr = raw_input()
v = list(map(int, arr.split()))

total = 0
for i in v:
    total += i

freq = []
for i in range(n):
    freq.append(v[i]/float(total))

freq.sort()
freq.reverse()

if freq[0] >= 0.45 or (freq[0] >= 0.4 and freq[0] - 0.1 >= freq[1]):
    print '1'
else:
    print '2'
