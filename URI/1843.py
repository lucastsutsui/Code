import copy

n = 0
m = 0
tab = []

def paint(comp,vis,x,lc):
    global n,m
    global tab
    q = []

    for i in range(n*m):
        if comp&(1<<i) != 0:
            q.append((i/m,i%m))
    
    while len(q) > 0:
        i,j = q.pop()

        if i > 0:
            if comp&(1<<((i-1)*m+j)) == 0 and (int(tab[(i-1)*m+j]) == lc or int(tab[(i-1)*m+j]) == x):
                q.append((i-1,j))
                comp |= (1<<((i-1)*m+j))
        if i < n-1:
            if comp&(1<<((i+1)*m+j)) == 0 and (int(tab[(i+1)*m+j]) == lc or int(tab[(i+1)*m+j]) == x):
                q.append((i+1,j))
                comp |= (1<<((i+1)*m+j))
        if j > 0:
            if comp&(1<<(i*m+j-1)) == 0 and (int(tab[i*m+j-1]) == lc or int(tab[i*m+j-1]) == x):
                q.append((i,j-1))
                comp |= (1<<(i*m+j-1))
        if j < m-1:
            if comp&(1<<(i*m+j+1)) == 0 and (int(tab[i*m+j+1]) == lc or int(tab[i*m+j+1]) == x):
                q.append((i,j+1))
                comp |= (1<<(i*m+j+1))
                     
    return comp

arr = raw_input()
n,m = map(int, arr.split())

for i in range(n):
    arr = list(raw_input())
    tab += arr

st = []
visited = dict()

# comp, dist, lc
st.append((1+(int(tab[0])<<(n*m)),0))
visited[1+(int(tab[0])<<(n*m))] = True

while len(st) > 0:
    comp,dist = st.pop(0)
    
    lc = comp>>(m*n)
    comp &= (1<<(m*n))-1
    
    if comp == (1<<(m*n))-1:
        print dist
        break

    for i in range(10):
        if i != lc:
            novo = paint(comp,0,i,lc)
            if not visited.has_key(novo+(i<<(n*m))):
                st.append((novo+(i<<(m*n)),dist+1))
                visited[novo+(i<<(n*m))] = True
        
