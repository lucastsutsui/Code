t = input()

for aos in range(t):
    arr = raw_input()
    n,m = map(int, arr.split())

    graf = []
    visited = []

    for i in range(n):
        graf.append([])

    for i in range(m):
        arr = raw_input()
        a,b = map(int, arr.split())

        graf[a-1].append(b-1)

    
