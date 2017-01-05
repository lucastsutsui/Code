def backtrack(i,n,memo):
    if i==n:
        return 1
    if i > n:
        return 0
    if memo[i] != -1:
        return memo[i]
    memo[i] = backtrack(i+1,n,memo) + backtrack(i+2,n,memo)
    return memo[i]

while True:
    n = input()
    if n==0:
        break
    memo = []
    for i in range(n):
        memo.append(-1)
        
    print backtrack(0,n,memo)
