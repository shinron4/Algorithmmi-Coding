#include <iostream>
#include <cmath> 
#include <queue>
#include <algorithm>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAXV 2000

using namespace std;

int color[MAXV + 1];

int s[2 * MAXV + 1], f[2 * MAXV + 1], t;
void visit1(const vector< vector<int> > & G, int u){
	s[t++] = u;
	color[u] = 1;
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(!color[v]) visit1(G, v);
	}
	f[t++] = u;
}

void dfs1(const vector< vector<int> > & G, int n){
	for(int i = 1; i <= n; i++) color[i] = 0;
	for(int i = 1; i <= n; i++) if(!color[i]) visit1(G, i);

}

int comp[MAXV + 1], c;
void visit2(const vector< vector<int> > & G, int u){
	color[u] = 1;
	comp[u] = c;
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(!color[v]) visit2(G, v);
	}
}

void dfs2(const vector< vector<int> > & G, int n){
	for(int i = 1; i <= n; i++) color[i] = 0;
	for(int j = t - 1; j >= 0; j--){
		if(f[j] > 0 && !color[f[j]]){
			visit2(G, f[j]);
			c++;
		}
	}
}

vector< vector<int> > G1(MAXV + 1), G2(MAXV + 1);

int scc(int n){
	for(int t = 1; t <= n; t++) f[t] =  s[t] = -1;
	t = 0;
	dfs1(G1, n);
	for(int j = 1; j <= n; j++) for(int k = 0; k < G1[j].size(); k++) G2[G1[j][k]].PB(j);
	for(int u = 1; u <= n; u++) comp[u] = 0; 
	c = 0;
	dfs2(G2, n);
	return c;
}

vector< pair<int, int> > compdeg(MAXV + 1);

int main(){
	int t, n, m, f, p;
	IN t;
	for(int i = 0; i < t; i++){
		IN n;
		for(int j = 1; j <= n; j++){
			IN m;
			for(int k = 0; k < m; k++){
				int v;
				IN v;
				G1[v].PB(j);
			}
		}
		scc(n);
		for(int j = 1; j <= n; j++){
			compdeg[comp[j]].F++;
			for(int k = 0; k < G1[j].size(); k++){
				int v = G1[j][k];
				if(comp[j] != comp[v]) compdeg[comp[v]].S++;
			}
		}
		f = 0;
		for(int j = 0; j < c; j++) if(!compdeg[j].S) p = (f++, j);
		if(!f || f > 1) OUT 0;
		else OUT compdeg[p].F;
		newline;
		for(int j = 1; j <= n; j++){
			G1[j].clear();
			G2[j].clear();
		}
		for(int j = 0; j < c; j++) compdeg[j].F = compdeg[j].S = 0;
	}

	return 0;
}