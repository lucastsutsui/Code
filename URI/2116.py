import math

def isPrime(n):
    if n<5 or n%2==0 or n%3==0:
        return (n==2 or n==3)
    lim = math.sqrt(n)+2
    i = 5
    while i < lim:
        if n%i==0 or n%(i+2)==0:
            return False
        i+=6
    return True

arr = raw_input()
n,m = map(int,arr.split())

while n > 2 and not isPrime(n):
    n-=1
while m > 2 and not isPrime(m):
    m-=1
    
print n*m
