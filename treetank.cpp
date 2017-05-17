#include <iostream>
#include <queue>
#include <climits>

#define PB push_back
#define MP make_pair
#define space cout << " "
#define newline cout << "\n"
#define S second
#define F first

using namespace std;

vector< vector< pair<int, int > > > G(100000);
vector<int> conn_comp;

int color[100000], color2[100000];

long long int bfs(int n, int s, int c){
	queue<int> q;
	int d[100000];
	long long int cost = 0;
	for(int i = 0; i < n; i++){
		color[conn_comp[i]] = 0;
	}
	d[s] = 0;
	color[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int j = 0; j < G[u].size(); j++){
			int v, w;
			v = G[u][j].F;
			w = G[u][j].S;
			if(c >= w){
				if(color[v] == 0){
					color[v] = 1;
					q.push(v);
					d[v] = d[u] + 1;
					cost += d[v];
				}
			}
		}
		color[u] = 2;
	}
	for(int i = 0; i < n; i++){
		cout << d[conn_comp[i]]; space;
	}
	newline;
	return cost;

}

long long int find_center(int n, int c){
	queue<int> q1, q2;
	int deg[100000];
	for(int i = 0; i < n; i++){
		color[conn_comp[i]] = 0;
	}
	for(int i = 0; i < n; i++){
		deg[conn_comp[i]] = 0;
		for(int j = 0; j < G[conn_comp[i]].size(); j++){
			int v, w;
			v = G[conn_comp[i]][j].F;
			w = G[conn_comp[i]][j].S;
			if(c >= w){
				deg[conn_comp[i]]++;
			}
		}
		if(deg[conn_comp[i]] < 2){
			q1.push(conn_comp[i]);
			color[conn_comp[i]] = 1;
		}
	}
	while(1){
		if(n > 2){
			if(!q1.empty()){
				while(!q1.empty()){
					int u = q1.front();
					for(int j = 0; j < G[u].size(); j++){
						int v, w;
						v = G[u][j].F;
						w = G[u][j].S;
						if(c >= w && color[v] == 0){
							deg[v]--;
							if(deg[v] < 2){
								q2.push(v);
								color[v] = 1;
							}
						}
					}
					q1.pop();
					n--;
				}
			}
			else if(!q2.empty()){
				while(!q2.empty()){
					int u = q2.front();
					for(int j = 0; j < G[u].size(); j++){
						int v, w;
						v = G[u][j].F;
						w = G[u][j].S;
						if(c >= w && color[v] == 0){
							deg[v]--;
							if(deg[v] < 2){
								q1.push(v);
								color[v] = 1;
							}
						}
					}
					q2.pop();
					n--;
				}
			}
		}
		else{
			break;
		}
	}
	long long int min = LLONG_MAX, x;
	if(q1.size() == 0){
		int k;
		while(!q2.empty()){
			k = q2.front();
			x = bfs(conn_comp.size(), k, c);
			if(x < min){
				min = x;
			}
			q2.pop();
		}
	}
	else{
		int k;
		while(!q1.empty()){
			k = q1.front();
			x = bfs(conn_comp.size(), k, c);
			if(x < min){
				min = x;
			}
			q1.pop();
		}

	}
	return min;
}

void visit(int u, int c){
	color2[u] = 1;
	for(int j = 0; j < G[u].size(); j++){
		int v, w;
		v = G[u][j].F;
		w = G[u][j].S;
		if(c >= w){
			if(color2[v] == 0){
				conn_comp.PB(v);
				visit(v, c);
			}
		}
	}
	color2[u] = 2;
}

long long int dfs(int n, int c){
	long long int k = 0;
	for(int i = 0; i < n; i++)
		color2[i] = 0;
	for(int i = 0; i < n; i++){
		if(color2[i] == 0){
			conn_comp.clear();
			conn_comp.PB(i);
			visit(i, c);
			k += find_center(conn_comp.size(), c);
		}
	}
	return k;
}

int main(){
	int n, u, v, w, maxc, minc = 1, midc, t;
	long long int k, cost;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v >> w;
		G[u - 1].PB(MP(v - 1, w));
		G[v - 1].PB(MP(u - 1, w));
	}
	maxc = 1000000000;
	while(minc < maxc){
		midc = (maxc + minc)/2;
		cost = dfs(n, midc);
		if(cost <= k){
			t = midc;
			minc = midc + 1;
		}
		else{
			maxc = midc;
		}
	}
	if(dfs(n, minc) <= k){
		cout << minc; newline;
	}
	else{
		cout << t; newline;
	}
	return 0;
}