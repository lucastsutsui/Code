arr = raw_input()
a,b,c = map(int, arr.split())

if a >= b+c or b >= a+c or c >= a+b:
    print 'n'
elif a*a == b*b+c*c or b*b == a*a+c*c or c*c==a*a+b*b:
    print 'r'
elif a*a < b*b+c*c and b*b < a*a+c*c and c*c < a*a+b*b:
    print 'a'
else:
    print 'o'
