#include <iostream>
#include <vector>
#include <queue>

#define MAX 10000000
#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector< vector< pair<int, int> > > G(500), GI(500);

class compare{
public:
	bool operator()(pair<int, int> &p, pair<int, int> &q){
		return p.S < q.S;
	}
};

void dijkstra(int n, int s, int d[], vector< vector < pair<int, int> > > G){
	bool c[n];
	priority_queue< pair<int, int>, vector< pair<int, int> >, compare > q;
	for(int i = 0; i < n; i++){
		d[i] = MAX;
		c[i] = false;
	}
	d[s] = 0;
	q.push(MP(s, 0));
	while(!q.empty()){
		int u = q.top().F;
		q.pop();
		if(!c[u]){
			for(int j = 0; j < G[u].size(); j++){
				int v = G[u][j].F, w = G[u][j].S;
				if(d[v] > d[u] + w){
					d[v] = d[u] + w;
					q.push(MP(v, d[v]));
				}
			}
			c[u] = true;
		}
	}
}

int main(){
	int n, m, s, d, dist1[500], dist2[500];
	fastIO
	while(true){
		IN n; IN m;
		if(n == 0) break;
		IN s; IN d;
		for(int i = 0; i < m; i++){
			int u, v, w;
			IN u; IN v; IN w;
			G[u].PB(MP(v, w));
		}
		dijkstra(n, s, dist1, G);
		if(dist1[d] == MAX) OUT -1;
		else{
			int m = dist1[d];
			for(int j = 0; j < n; j++)
				for(int k = 0; k < G[j].size(); k++)
					GI[G[j][k].F].PB(MP(j, G[j][k].S));
			dijkstra(n, d, dist2, GI);
			for(int j = 0; j < n; j++) GI[j].clear();
			for(int j = 0; j < n; j++){
				for(int k = 0; k < G[j].size(); k++){
					int u = j, v = G[j][k].F, w = G[j][k].S;
					if(dist1[u] + w + dist2[v] != m) GI[u].PB(MP(v, w));
				}
			}
			dijkstra(n, s, dist1, GI);
			OUT (dist1[d] < MAX ? dist1[d] : -1);
		}
		for(int j = 0; j < n; j++){
			GI[j].clear();
			G[j].clear();
		}
		newline;
	}
	return 0;
}