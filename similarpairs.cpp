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

using namespace std;

long int c[100005];
long int cnt;
vector< vector<int> > G(100005);
int color[100005];

long int get(int i){
	long int sum = 0;
	while(i > 0){
		sum += c[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		c[i] += val;
		i += i & -i;
	}
}

void visit(int n, int u, int k){
	int l, r;
	color[u] = 0;
	update(n, u, 1);
	l = u - k < 1 ? 1 : u - k;
	r = u + k > n ? n : u + k;
	cnt += (get(u - 1) - get(l - 1)) + (get(r) - get(u));
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(color[v] == 1){
			visit(n, v, k);
		}
	}
	update(n, u, -1);
}

int main(){
	int n, k, p, c, u;
	IN n; IN k;
	for(int i = 0; i < n - 1; i++){
		IN p; IN c;
		G[p].PB(c);
		color[c] = 1;
	}
	u = 1;
	while(u <= n){ 
		if(!color[u])
			break;
		u++;
	}
	color[u] = 1;
	visit(n, u, k);
	OUT cnt; newline;
	return 0;
}