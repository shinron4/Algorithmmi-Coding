#include <iostream>
#include <vector>
#include <algorithm>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define compx(p, q) (p.x < q.x || (p.x == q.x && p.y < q.y))
#define compy(p, q) (p.y < q.y || (p.y == q.y && p.x < q.x))

using namespace std;

struct point{
	int x, y;
};

vector<struct point> vp;

struct COMPX{
	bool operator()(int i, int j){
		return compx(vp[i], vp[j]);
	}
} comp_x_maj;

struct COMPY{
	bool operator()(int i, int j){
		return compy(vp[i], vp[j]);
	}
} comp_y_maj;

vector< vector<int> > G(1001);
vector<int> start(1001), color(1001);
int s_t;

struct COMPS{
	bool operator() (int i, int j){
		return start[i] < start[j];
	}
} comp_start;

void visit(int u){
	color[u] = 1;
	start[u] = ++s_t;
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(color[v] == 0) visit(v);
	}
}

int main(){
	while(1){
		int n, s;
		struct point p;
		IN n;
		if(n == 0) break;
		vector<int> v_int;
		vp.clear();
		v_int.clear();
		for(int i = 0; i < n; i++){
			IN p.x; IN p.y;
			v_int.PB(i);
			vp.PB(p);
		}
		for(int i = 0; i < n; i++) G[i].clear();
		sort(v_int.begin(), v_int.end(), comp_x_maj);
		bool f = true;
		s = v_int[0];
		for(int i = 0; i < n - 1; i++){
			if(vp[v_int[i]].x == vp[v_int[i + 1]].x && f){
				G[v_int[i]].PB(v_int[i + 1]);
				G[v_int[i + 1]].PB(v_int[i]);
				f = false;
			}
			else f = true;
		}
		sort(v_int.begin(), v_int.end(), comp_y_maj);
		f = true;
		for(int i = 0; i < n - 1; i++){
			if(vp[v_int[i]].y == vp[v_int[i + 1]].y && f){
				G[v_int[i]].PB(v_int[i + 1]);
				G[v_int[i + 1]].PB(v_int[i]);
				f = false;
			}
			else f = true;
		}
		for(int i = 0; i < n; i++) color[i] = 0;
		s_t = 0;
		color[0] = 1;
		visit(0);
		sort(v_int.begin(), v_int.end(), comp_start);
		int u, clock = 1;
		for(int i = 0; i < n; i++) if(v_int[i] == s) u = v_int[(i + 1) % n];
		if(vp[s].y == vp[u].y) clock = 0; 
		if(clock){
			for(int i = 0; i < n; i++){
				if(vp[v_int[i]].x == vp[v_int[(i + 1) % n]].x){
					if(vp[v_int[i]].y < vp[v_int[(i + 1) % n]].y) OUT "N";
					else OUT "S";
				}
				else{
					if(vp[v_int[i]].x < vp[v_int[(i + 1) % n]].x) OUT "E";
					else OUT "W";
				}
			}
		}
		else{
			for(int i = n - 1; i >= 0; i--){
				if(vp[v_int[(i + 1) % n]].x == vp[v_int[i]].x){
					if(vp[v_int[(i + 1) % n]].y < vp[v_int[i]].y) OUT "N";
					else OUT "S";
				}
				else{
					if(vp[v_int[(i + 1) % n]].x < vp[v_int[i]].x) OUT "E";
					else OUT "W";
				}
			}

		}
		newline;
	}
	return 0;
}