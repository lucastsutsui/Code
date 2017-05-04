#include <iostream>
using namespace std;

int n, x[2001], y[2001];
long long int cont=0;

int main() 
{
    ios::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	    
	for (int i = 0; i < n-2; i++)
	    for (int j = i+1; j < n-1; j++){
	        int c = (y[k]-y[i])*(x[j]-x[i]);
	        for (int k = j+1; k < n; k++)
	            if (c != (y[j]-y[i])*(x[k]-x[i])) cont++;
	    }
	        
	cout << cont;
	
	return 0;
}
