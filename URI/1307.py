def mdc(x,y):
    if y==0:
        return abs(x)
    return mdc(y, x%y)

def toN(x):
    x = x[::-1]
    n = 0
    for i in range(len(x)):
        if x[i] == '1':
            n += (1<<i)
    return n

n = input()

for i in range(n):
    s1 = raw_input()
    s2 = raw_input()

    x = toN(s1)
    y = toN(s2)

    print 'Pair #'+str(i+1)+':',
    if mdc(x,y) > 1:
        print 'All you need is love!'
    else:
        print 'Love is not all you need!'
