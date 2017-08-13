#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define PI 3.14159265
#define EPSILON 1e-9

using namespace std;

struct point{
	int x, y;
};

double angle(double x, double y){
	double t = atan2 (y, x) * 180.0 / PI;
	return t >= 0 ? t : 360 - fabs(t);
}
double dist(const struct point &p, const struct point &q){
	return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}

class compare{
public:
	bool operator()(const pair<int, double> &p, pair<int, double> &q){
		if(fabs(p.S - q.S) > EPSILON) return p.S > q.S;
		else if(p.F ^ q.F) return q.F == 0;
		else return true;
	}
};

priority_queue< pair<int, double>, vector< pair<int, double> >, compare > eq;

int main(){
	struct point p;
	while(1){
		int n, D;
		vector<struct point> vp;
		IN n; IN D;
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			IN p.x ; IN p.y;
			vp.PB(p);
		}
		D <<= 1;
		pair<int, double> max;
		int count = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					double theta = angle(vp[j].x - vp[i].x, vp[j].y - vp[i].y);
					double d = dist(vp[i], vp[j]);
					if(fabs(d - D) > EPSILON && d > D) continue; 
					double phi = acos(d/D) * 180.0 / PI, beg = theta - phi, end;
					beg = beg < 0 ? 360 - fabs(beg) : beg;
					eq.push(MP(0, beg));
					if(fabs(beg - 0) < EPSILON){
						eq.push(MP(0, 360));
						eq.push(MP(1, 360));
					}
					end = beg + 2 * phi;
					if(fabs(end - 360) > EPSILON){
						if(end > 360){
							eq.push(MP(1, 360));
							eq.push(MP(0, 0));
							eq.push(MP(1, end - 360));
						}
						else eq.push(MP(1, end));
					}
					else{
						eq.push(MP(1, 360));
						eq.push(MP(0, 0));
						eq.push(MP(1, 0));
					}
				}
				else{
					eq.push(MP(0, 0));
					eq.push(MP(1, 360));
				}
			}
			int t_c = 0;
			while(!eq.empty()){
				if(eq.top().F == 0){
					t_c++;
					if(t_c > count){
						max.F = i;
						max.S = eq.top().S;
						count = t_c;
					}
				}
				else t_c--;
				eq.pop();
			}
		}
		cout<<  "It is possible to cover " << count <<  " points.\n";
	}
	return 0;
}