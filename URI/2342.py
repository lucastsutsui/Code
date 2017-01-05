n = input()

arr = raw_input()
p,op,q = map(str, arr.split())
p = int(p)
q = int(q)

if op == '+' and p+q<=n:
    print 'OK'
elif op == '*' and p*q<=n:
    print 'OK'
else:
    print 'OVERFLOW'
