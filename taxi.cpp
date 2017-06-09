#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <queue>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define LLI long long int 
#define LI long int
#define LP(type, var, init, max, step) for(type var = init; var <= max; var += step)
#define LPA(type, var, max) LP(type, var, 0, max - 1, 1)
#define abs(a) ((a) > 0 ? (a) : -(a))
using namespace std;

vector< vector<LLI> > G(602);
LLI f[602][602], c[602][602], cf[602][602], e[602], l[602], h[602];
queue<LLI> q; 

void init(LLI n, LLI s, LLI t){
	LPA(LLI, i, n){
		h[i] = i == s ? n : 0;
		l[i] = e[i] = 0;
	}
	LPA(LLI, i, n){
		LPA(LLI, j, G[i].size()){
			LLI v = G[i][j];
			f[i][v] = 0;
		}
	}
	LPA(LLI, i, G[s].size()){
		LLI v = G[s][i], w = c[s][v];
		f[s][v] = e[v] = w;
		f[v][s] = -f[s][v];
		e[s] -= w;
		cf[s][v] = c[s][v] - f[s][v];
		cf[v][s] = c[v][s] - f[v][s];
		if(!l[v] && v != t) l[v] = (q.push(v), 1);
	}
}

void push(LLI u, LLI v){
	LLI w = cf[u][v], temp = e[u] < w ? e[u] : w;
	f[u][v] += temp;
	f[v][u] = -f[u][v];
	e[u] -= temp;
	e[v] += temp;
	cf[u][v] = c[u][v] - f[u][v];
	cf[v][u] = c[v][u] - f[v][u];
}

LLI maxflow(LLI n, LLI s, LLI t){
	LLI temp, u;

	while(!q.empty()){
		u = q.front();
		temp = 2 * n;
		for(LLI j = 0; j < G[u].size() && e[u] > 0; j++){
			LLI v = G[u][j], w = cf[u][v];
			if(w > 0){
				if(h[v] < h[u]){
					push(u, v);
					if(!l[v] && v != s && v != t) l[v] = (q.push(v), 1);
				}
				else temp = h[v] < temp ? h[v] : temp;
			}
		}
		if(e[u]) h[u] = temp + 1;
		else l[u] = (q.pop(), 0);
	}
	return e[t];
}

vector< pair<LLI, LLI> > person(401), taxi(201);

int main(){
	LLI k, p, t, s, g;
	IN k;
	for(LLI i = 0; i < k; i++){
		IN p; IN t; IN s; IN g;
		for(LLI j = 1; j <= p; j++){
			IN person[j].F; IN person[j].S;
		}
		for(LLI j = 1; j <= t; j++){
			IN taxi[j].F; IN taxi[j].S;
			for(LLI l = 1; l <= p; l++){
				float time = (abs(person[l].F - taxi[j].F) + abs(person[l].S - taxi[j].S)) * 200 / s;
				if(time <= g){
					G[j].PB(l + t);
					G[l + t].PB(j);
					cf[j][l + t] = c[j][l + t] = 1;
					cf[l + t][j] = c[l + t][j] = 0;
				}
			}
		}
		for(LLI j = 1; j <= t; j++){
			cf[0][j] = c[0][j] = 1;
			cf[j][0] = c[j][0] = 0;
			G[j].PB(0);
			G[0].PB(j);
		}  
		for(LLI j = 1; j <= p; j++){
			cf[t + j][p + t + 1] = c[t + j][p + t + 1] = 1;
			cf[p + t + 1][t + j] = c[p + t + 1][t + j] = 0;
			G[t + j].PB(p + t + 1);
			G[p + t + 1].PB(t + j);
		} 
		init(p + t + 2, 0, p + t + 1);
		OUT maxflow(p + t + 2, 0, p + t + 1); newline;
		LPA(LLI, j, p + t + 2) G[j].clear();
	}
	return 0;
}