import sys

def p():
    sys.stdout.softspace = 0

arr = raw_input()
a,b,c = map(int, arr.split())

if a<b+c and b<a+c and c<a+b:
    p()
    print 'Valido-',
    if a==b and b==c:
        p()
        print 'Equilatero'
    elif a==b or b==c or a==c:
        p()
        print 'Isoceles'
    else:
        p()
        print 'Escaleno'
    if a*a==b*b+c*c or b*b==a*a+c*c or c*c==a*a+b*b:
        print 'Retangulo: S'
    else:
        print 'Retangulo: N'
else:
    print 'Invalido'
