#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>

using namespace std;

#define PB push_back 
#define MP make_pair
#define F first
#define S second
#define rep(i, h, s) for(long long l = i; l < h; l += s)

vector < vector< pair<int, int> > > G(400);

class compare{
	public: 
		bool operator()(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2){
			return p1.F > p2.F;
		}
};

priority_queue< pair<long long, pair<long long, int> >, vector< pair<long long , pair<long long , int> > >, compare > Q;

long long d[1 << 15][400];
bool visit[1<< 15][400];

int main(){
	int n, m, k, u, v, w, mask;
	map<int, int> mp;
	cin >> n >> m >> k;
	rep(0, m, 1){
		cin >> u >> v >> w;
		G[u - 1].PB(MP(v - 1, w));
		G[v - 1].PB(MP(u - 1, w));
	}
	rep(0, k, 1){
		cin >> u;
		mp[u - 1] = l;
	}
	for(long long p = 0; p < 1 << k; p++)
		rep(0, n, 1){
			d[p][l] = INT_MAX;
		}
	d[0][0] = 0;
	Q.push(MP(d[0][0], MP(0, 0)));
	while(!Q.empty()){
		w = Q.top().F;
		u = Q.top().S.S;
		mask = Q.top().S.F;
		Q.pop();
		if(mask == (1 << k) - 1 && u == n - 1)
			break;
		if(visit[mask][u])
			continue;
		visit[mask][u] = true;
		rep(0, G[u].size(), 1){
			int newmask, v = G[u][l].F, c = G[u][l].S;
			newmask = mask | (mp.count(v) > 0 ? (1 << mp[v]) : 0);
			if(d[newmask][v] > w + c){
					d[newmask][v] = w + c;
					Q.push(MP(d[newmask][v], MP(newmask, v)));
			}
		}
	}
	cout << d[(1 << k) - 1][n - 1];
	return 0;
}