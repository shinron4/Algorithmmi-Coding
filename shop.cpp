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

using namespace std;

char shop[25][25];
pair<char, long long int> d[25][25];

class compare{
public:
	bool operator()(const pair<long long int, pair<int, int> > &a, const pair<long long int, pair<int, int> > &b){
		return a.F > b.F;
	}
};

priority_queue< pair<long long int, pair<int, int> >, vector< pair<long long int, pair<int, int> > >, compare > pq;

int main(){
	fastIO
	int w, h;
	while(1){
		IN w; IN h;
		if(!w || !h) break;
		pair<int, int> src, dst;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				IN shop[i][j];
				if(shop[i][j] == 'S'){
					src.F = i; src.S = j;
				}
				else if(shop[i][j] == 'D'){
					dst.F = i; dst.S = j;
				}
				d[i][j].F = '0';
				d[i][j].S = INT_MAX;
			}
		}
		d[src.F][src.S].S = 0;
		pq.push(MP(d[src.F][src.S].S,src));
		while(!pq.empty()){
			int u, v, wt;
			u = pq.top().S.F;
			v = pq.top().S.S;
			pq.pop();
			if(d[u][v].F == '0'){
				d[u][v].F = '1';
				if(u - 1 >= 0 && shop[u - 1][v] != 'X' && d[u - 1][v].F == '0'){
					wt = shop[u - 1][v] == 'D' ? 0 : shop[u - 1][v] - '0';
					if(d[u - 1][v].S > d[u][v].S + wt ){
						d[u - 1][v].S = d[u][v].S + wt;
						pq.push(MP(d[u - 1][v].S, MP(u - 1, v)));
					}
				}
				if(u + 1 < h && shop[u + 1][v] != 'X' && d[u + 1][v].F == '0'){
					wt = shop[u + 1][v] == 'D' ? 0 : shop[u + 1][v] - '0';
					if(d[u + 1][v].S > d[u][v].S + wt ){
						d[u + 1][v].S = d[u][v].S + wt;
						pq.push(MP(d[u + 1][v].S, MP(u + 1, v)));
					}
				}
				if(v - 1 >= 0 && shop[u][v - 1] != 'X' && d[u][v - 1].F == '0'){
					wt = shop[u][v - 1] == 'D' ? 0 : shop[u][v - 1] - '0';
					if(d[u][v - 1].S > d[u][v].S + wt ){
						d[u][v - 1].S = d[u][v].S + wt;
						pq.push(MP(d[u][v - 1].S, MP(u, v - 1)));
					}
				}
				if(v + 1 < w && shop[u][v + 1] != 'X' && d[u][v + 1].F == '0'){
					wt = shop[u][v + 1] == 'D' ? 0 : shop[u][v + 1] - '0';
					if(d[u][v + 1].S > d[u][v].S + wt ){
						d[u][v + 1].S = d[u][v].S + wt;
						pq.push(MP(d[u][v + 1].S, MP(u, v + 1)));
					}
				}
			}
		}
		OUT d[dst.F][dst.S].S; newline;
	}
	return 0;
}