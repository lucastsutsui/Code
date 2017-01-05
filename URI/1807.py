mod = 2147483647

def exp(n):
    if n == 0:
        return 1
    
    m = exp(n/2)%mod
    
    if n%2==0:
        return (m*m)%mod
    else:
        return (m*m*3)%mod

n = input()

print exp(n)
