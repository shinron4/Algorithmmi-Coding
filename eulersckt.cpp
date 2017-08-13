#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAXV 26

using namespace std;

//Adjacency list implementation
vector< vector<int> > G(MAXV + 1);

//Assuming that it is euler graph

//Also finds disjoint euler circiut
vector<int> ckt;
stack<int> curr_path;
int eulerckt(int n, int indeg[], int outdeg[]){
	for(int i = 1; i <= n; i++) if(indeg[i] != outdeg[i]) return 0;
	int u = -1, deg[n + 1], t = 0;
	for(int i = 1; i <= n; i++) if(deg[i] = outdeg[i]) u = i;
	while(u > 0){
		do{
			if(deg[u]) u = (curr_path.push(u), G[u][--deg[u]]);
			else{
				ckt.PB(u);
				u = curr_path.top();
				curr_path.pop();
			}
		}while(!curr_path.empty());
		ckt.PB(u);
		t++;
		u = -1;
		for(int i = 1; i <= n; i++) if(deg[i]) u = i;
	}
	return t;
}

int main(){
	fastIO
	int t, n, indeg[MAXV + 1], outdeg[MAXV + 1], p;
	string s;
	IN t;
	for(int i = 0; i < t; i++){
		IN n;
		for(int j = 1; j <= MAXV; j++) indeg[j] = outdeg[j] = 0;
		for(int j = 0; j < n; j++){
			IN s;
			int u = s[0] - 'a' + 1, v = s[s.size() - 1] - 'a' + 1;
			outdeg[u]++; indeg[v]++;
			G[u].PB(v);
		}
		int f = 0, u, v;
		for(int j = 1; j <= MAXV; j++){
			if(indeg[j] != outdeg[j]){
				if(!f) u = j;
				else v = j;
				f++;
			}
		}
		if(f == 2){
			if(indeg[u] > outdeg[u] && indeg[v] < outdeg[v]){
				G[u].PB(v);
				outdeg[u]++; indeg[v]++;
			}
			if(indeg[u] < outdeg[u] && indeg[v] > outdeg[v]){
				G[v].PB(u);
				outdeg[v]++; indeg[u]++;
			}
		}
		if(!(p = eulerckt(MAXV, indeg, outdeg)) || p > 1) OUT "The door cannot be opened.";
		else OUT "Ordering is possible.";
		newline;
		for(int j = 1; j <= MAXV; j++) G[j].clear();
		ckt.clear();
	}
	return 0;
}