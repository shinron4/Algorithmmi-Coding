#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define LLI long long int 
#define LI long int
#define LP(type, var, init, max, step) for(type var = init; var <= max; var += step)
#define LPA(type, var, max) LP(type, var, 0, max - 1, 1)
#define abs(a) ((a) > 0 ? (a) : -(a))
using namespace std;

vector< vector<int> > G(201);
int f[201][201], c[201][201], cf[201][201], e[201], l[201], h[201];
queue<int> q; 

void init(int n, int s, int t){
	for(int i = 1; i <= n; i++){
		h[i] = i == s ? n : 0;
		e[i] = l[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			int v = G[i][j];
			f[i][v] = 0;
		}
	}
	for(int i = 0; i < G[s].size(); i++){
		int v = G[s][i], w = cf[s][v];
		f[s][v] = e[v] = w;
		f[v][s] = -f[s][v];
		e[s] -= w;
		cf[s][v] = c[s][v] - f[s][v];
		cf[v][s] = c[v][s] - f[v][s];
		if(!l[v] && v != t && v != s) l[v] = (q.push(v), 1);
	}
}

void push(int u, int v){
	int w = cf[u][v], t = e[u] < w ? e[u] : w;
	f[u][v] += t;
	f[v][u] = -f[u][v];
	e[u] -= t;
	e[v] += t;
	cf[u][v] = c[u][v] - f[u][v];
	cf[v][u] = c[v][u] - f[v][u];
}

int maxflow(int n, int s, int t){
	int temp, u;
	while(!q.empty()){
		u = q.front();
		temp = 2 * n;
		for(int i = 0; i < G[u].size() && e[u] > 0; i++){
			int v = G[u][i], w = cf[u][v];
			if(w > 0){
				if(h[v] < h[u]){
					push(u, v);
					if(!l[v] && v != s && v != t) l[v] = (q.push(v), 1);
				}
				else temp = h[v] < temp ? h[v] : temp;
			}
		}
		if(e[u] != 0) h[u] = temp + 1;
		else l[u] = (q.pop(), 0);
	}
	return e[t];
}

int main(){
	int t, n, m, v;
	IN t; 
	for(int i = 0; i < t; i++){
		IN n;
		for(int j = 1; j <= n - 1; j++){
			IN m;
			for(int k = 0; k < m; k++){
				IN v;
				G[j].PB(v);
				G[v].PB(j);
				c[j][v] = cf[j][v] = j == 1 || v == n ? 1 : INT_MAX;
				c[v][j] = cf[v][j] = 0;
			}
		}
		init(n, 1, n);
		OUT maxflow(n, 1, n); newline;
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < G[j].size(); k++){
				int v = G[j][k];
				c[j][v] = cf[j][v] = 0;
				c[v][j] = cf[v][j] = 0;
			}
			G[j].clear();
		}
	}
	return 0;
}