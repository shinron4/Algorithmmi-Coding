#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > adjlist(100000);
int color[100000], paths[100000];


int visit(int v){
	color[v] = 1;
	for(int j = 0; j < adjlist[v].size(); j++)
		if(color[adjlist[v][j]] == 0)
			paths[v] += visit(adjlist[v][j]);
	color[v] = 2;
	paths[v] += (v != 0 ? 1 : 0);
	return paths[v];
}

int main(){
	int n, u, v;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		adjlist[u - 1].push_back(v - 1);
		adjlist[v - 1].push_back(u - 1);
	}
	visit(0);
	for(int i = 0; i < n; i++)
		cout << paths[i] << " "; 
	return 0;
}