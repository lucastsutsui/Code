arr = raw_input()
c,p,f = map(int, arr.split())

if c*f <= p:
    print 'S'
else:
    print 'N'
