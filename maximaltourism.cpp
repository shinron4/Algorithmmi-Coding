#include <iostream>
#include <cmath> 
#include <vector>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 

using namespace std;

vector< vector< int > > G(100000);
int c[100000], msize = 0;

int visit(int u){
	int s = 0, v;
	c[u] = 1;
	for(int j = 0; j < G[u].size(); j++){
		v = G[u][j];
		if(c[v] == 0){
			s += visit(v);
		}
	}
	c[u] = 2;
	return s + 1;
}

int dfs(int n){
	int s = 0;
	for(int i = 0; i < n; i++){
		if(c[i] == 0){
			s = visit(i);
			if(s > msize){
				msize = s;
			}
		}
	}
	return msize;
}

int main(){
	int n, m, u, v;
	IN n; IN m;
	for(int i = 0; i < m; i++){
		IN u; IN v;
		G[u - 1].PB(v - 1);
		if(u != v)
			G[v - 1].PB(u - 1);
	}
	OUT dfs(n); newline;
}