import math

casos = input()

while casos:
    n = input()

    x = math.floor((-1.0+math.sqrt(1.0+8.0*float(n)))/2.0)

    print int(x)
    
    casos-=1
