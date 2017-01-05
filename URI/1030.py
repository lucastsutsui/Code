def f(n,k):
    if n == 1:
        return 1
    acc = 1
    for i in range(1,n):
        acc = ((k-1+acc)%i)+1
    return acc
    #return ((k-1+f(n-1,k))%n) + 1

nc = input()
for arsads in range(nc):
    arr = raw_input()
    n,k = map(int,arr.split())
    print f(n,k)
    
