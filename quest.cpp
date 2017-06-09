#include <iostream>
#include <queue>
#include <vector>
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
#define MAXV 242

using namespace std;

struct neighbour{
	int t, sym;
	int cap, fl;
};
vector< vector<struct neighbour> > G(MAXV + 1);
void addedge(int u, int v, int w){
	int t1, t2;
	struct neighbour t;
	t1 = G[u].size();
	t2 = G[v].size();
	t.t = v;
	t.sym = t2;
	t.fl = 0;
	t.cap = w;
	G[u].PB(t);
	t.t = u;
	t.sym = t1;
	t.fl = 0;
	t.cap = 0;
	G[v].PB(t);
}
void cleargraph(int n){
	for(int i = 1; i <= n; i++) G[i].clear();
}

int d[MAXV + 1], ptr[MAXV + 1];
bool bfs(int n, int s, int t){
	queue<int> q;
	for(int i = 1; i <= n; i++) d[i] = INT_MAX;
	d[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].t;
			if(d[v] == INT_MAX && G[u][i].fl < G[u][i].cap) d[v] = (q.push(v), d[u] + 1);
		}
	}
	return d[t] != INT_MAX;
}

int dfs(int u, int t, int f){
	int push = 0;
	if(!f) return 0;
	if(u == t) return f;
	for(int &i = ptr[u]; i < G[u].size(); i++){
		int j = G[u][i].sym, v = G[u][i].t;
		if(d[v] == d[u] + 1 && G[u][i].fl < G[u][i].cap){
			push = dfs(v, t, min(f, G[u][i].cap - G[u][i].fl));
			if(push){
				G[u][i].fl += push;
				G[v][j].fl = -G[u][i].fl;
				return push;
			}
		}
	}
	return 0;
}

int maxflow(int n, int s, int t){
	int f  = 0;
	while(bfs(n, s, t)){
		for(int i = 1; i <= n; i++) ptr[i] = 0;
		f += dfs(s, t, INT_MAX);
	}
	return f;
}

int main(){
	int t, n, x, y;
	IN t;
	for(int i = 0; i < t; i++){
		IN n;
		for(int j = 1; j <= n; j++){
			IN x; IN y;
			x++; y++;
			addedge(x, 120 + y, 1);
		}
		for(int j = 1; j <= 120; j++) addedge(241, j, 1);
		for(int j = 1; j <= 120; j++) addedge(120 + j, 242, 1);
		OUT maxflow(242, 241, 242); newline;
		cleargraph(242);
	}
	return 0;
}