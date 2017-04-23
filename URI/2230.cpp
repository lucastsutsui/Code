#include <bits/stdc++.h>
using namespace std;

int c,e,l,p;
vector<int> ans;
bool visited[60];

int main() 
{
    int x,y,test=1;
    
    while (1){
        scanf("%d %d %d %d", &c, &e, &l, &p);
        if (c==0 && e==0 && l==0 && p==0) break;
        
        vector<vector<int> > graph(c);
        
        for (int i = 0; i < e; i++){
            scanf("%d %d", &x, &y); x--; y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        for (int i = 0; i < c; i++) visited[i] = false;
        
        ans.clear();
        queue<pair<int,int> > fila;
        fila.push(make_pair(l-1,0));
        visited[l-1] = true;
        
        while (fila.size()){
            int i = fila.front().first, d = fila.front().second;
            fila.pop();
            
            if (d <= p && i != l-1) ans.push_back(i+1);
            else if (d > p) continue;
            
            for (int j = 0; j < graph[i].size(); j++){
                if (!visited[graph[i][j]]){
                    fila.push(make_pair(graph[i][j],d+1));
                    visited[graph[i][j]] = true;
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        printf("Teste %d\n", test++);
        for (int i = 0; i < ans.size(); i++) printf ("%d ", ans[i]);
        printf ("\n\n");
    }
    
    return 0;
}
