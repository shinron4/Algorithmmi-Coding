#include <iostream>
#include <algorithm>
#include <vector>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "

using namespace std;

vector <int> data;
vector < vector<int> > G(100);
int tree[100], color[100], t[100], x;

int visit(int u){
	color[u] = 1;
	t[u] = ++x;
	tree[u] = data[u];
	for(int v = 0; v < G[u].size(); v++){
		if(color[G[u][v]] == 0){
			tree[u] += visit(G[u][v]);
		}
	}
	color[u] = 2;
	return tree[u];
}

int main(){
	int n, x, u, v, min = 1000000000,s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		data.PB(x);
		s += x;
	}
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		G[u - 1].PB(v - 1);
		G[v - 1].PB(u - 1);
	}
	visit(0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < G[i].size(); j++){
			u = i;
			v = G[i][j];
			if(t[u] > t[v]){
				if(abs(s - 2 * tree[u]) < min){
					min = abs(s - 2 * tree[u]);
				}	
			}
			else{
				if(abs(s - 2 * tree[v]) < min){
					min = abs(s - 2 * tree[v]);
				}	
			}
		}
	}
	cout << min; newline;
	return 0;
}