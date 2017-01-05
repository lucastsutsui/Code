def zero(x):
    v = ''
    while x:
        if x%10 != 0:
            v += str(x%10)
        x /= 10
    v = v[::-1]
    return v

while True:
    arr = raw_input()
    m,n = map(int, arr.split())
    if n==0 and m==0:
        break
    print zero(m+n)
