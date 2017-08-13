#include <iostream>
#include <vector>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAXV 5000

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
	for(int j = 1; j <= n; j++) color[j] = 0;
	for(int j = 1; j <= n; j++) if(!color[j]) visit1(G, j);
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
	for(int j = 1; j <= n; j++) color[j] = 0;
	for(int j = t - 1; j >= 0; j--){
		if(f[j] > 0 && !color[f[j]]){
			visit2(G, f[j]);
			c++;
		}
	}
}

vector< vector<int> > G1(MAXV + 1), G2(MAXV + 1);

int scc(int n){
	for(int j = 0; j < 2 * n; j++) s[j] = f[j] = -1;
	t = 0;
	dfs1(G1, n);
	for(int j = 1; j <= n; j++) for(int k = 0; k < G1[j].size(); k++) G2[G1[j][k]].PB(j);
	for(int j = 0; j < n; j++) comp[j] = 0;
	c = 0;
	dfs2(G2, n);
	return c;
}

int compdeg[MAXV + 1];

int main(){
	int n, m; 
	while(1){
		IN n;
		if(!n) break;
		IN m;
		for(int i = 0; i < m; i++){
			int u, v;
			IN u; IN v;
			G1[u].PB(v);
		}
		scc(n);
		//OUT "r1\n";
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < G1[i].size(); j++){
				int v = G1[i][j];
				if(comp[i] != comp[v]) compdeg[comp[i]]++;
			}
		}
		for(int i = 1; i <= n; i++) if(!compdeg[comp[i]]) { OUT i; space;}
		newline;
		for(int i = 1; i <= n; i++){
			G1[i].clear();
			G2[i].clear();
		}
		for(int i = 0; i < c; i++) compdeg[i] = 0;

	}
	return 0;
}