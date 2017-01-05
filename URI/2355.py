import math
while True:
    n = input()
    if n == 0:
        break
    print 'Brasil', int(math.floor(n/90.0)), 'x', 'Alemanha', int(math.ceil(n*7.0/90.0))
