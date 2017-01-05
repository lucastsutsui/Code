pi = 3.14

while True:
    try:
        v = input()
        d = input()
    except EOFError:
        break

    d = d/2.0
    h = v/(pi*d*d)
    area = (pi*d*d)

    print 'ALTURA =', "%.2f" % h
    print 'AREA =', "%.2f" % area
