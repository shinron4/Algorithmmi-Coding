#include <iostream>
#include <vector>
#include <stack>
#include <cfloat>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define next(a, n) ((a + 1) % n)

using namespace std;

struct point{
	double x, y;
};

double area(const struct point &p1, const struct point &p2, const struct point &p3){
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool smaller(const struct point &p1, const struct point &p2){
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

struct point m;
struct Comp{
	bool operator()(const struct point &p1, const struct point &p2){
		int a = area(m, p1, p2);
		if(a > 0) return true;
		else if(a == 0 && smaller(p1, p2)) return true;
		else return false;
	}
} compare;
vector<struct point> hull, boundary(1000000);

int convex_hull(){
	int n = hull.size();
	if(n == 0) return n;
	stack<struct point> s;
	for(int i = 0; i < n; i++) if(smaller(hull[i], m)) m = hull[i];
	sort(hull.begin(), hull.end(), compare);
	s.push(hull[0]);
	if(n > 1){
		s.push(hull[1]);
		for(int i = 2; i < n; i++){
			struct point t = s.top();
			s.pop();
			while(!s.empty() && area(s.top(), t, hull[i]) <= 0){
				t = s.top();
				s.pop();
			}
			s.push(t);
			s.push(hull[i]);
		}
	}
	int i = (n = s.size()) - 1;
	while(!s.empty()){
		boundary[i--] = s.top();
		s.pop();
	}
	return n;
}

double mag(const struct point &v){
	return sqrt(v.x * v.x + v.y * v.y);
}

double rad(const struct point &v1, const struct point &v2){
	double s = (v1.x * v2.x + v1.y * v2.y)/(mag(v1) * mag(v2));
	return acos(s);
}

vector< pair<int, double> > rect(4);

double minAenclose(vector<struct point> &pt, int n){
	struct point p0, p1, p2, p3;
	p0.x = p0.y = p1.y = p3.x = DBL_MAX;
	p1.x = p2.x = p2.y = p3.y = DBL_MIN;
 	for(int i = 0; i < n; i++){
 		if(p0.x > pt[i].x || (p0.x == pt[i].x && p0.y > pt[i].y)){
 			p0.x = pt[i].x;
 			p0.y = pt[i].y;
 			rect[0].F = i;
 		}
 		if(p1.y > pt[i].y || (p1.y == pt[i].y && p1.x < pt[i].x)){
 			p1.x = pt[i].x;
 			p1.y = pt[i].y;
 			rect[1].F = i;
 		}
 		if(p2.x < pt[i].x || (p2.x == pt[i].x && p2.y < pt[i].y)){
 			p2.x = pt[i].x;
 			p2.y = pt[i].y;
 			rect[2].F = i;
 		}
 		if(p3.y < pt[i].y || (p2.y == pt[i].y && p3.x > pt[i].x)){
 			p3.x = pt[i].x;
 			p3.y = pt[i].y;
 			rect[3].F = i;
 		}
	}
	struct point t, u;
	t.x = pt[next(rect[0].F, n)].x - pt[rect[0].F].x;
	t.y = pt[next(rect[0].F, n)].y - pt[rect[0].F].y;
	u.x = 0;
	u.y = -1;
	rect[0].S = rad(u, t); 
	t.x = pt[next(rect[1].F, n)].x - pt[rect[1].F].x;
	t.y = pt[next(rect[1].F, n)].y - pt[rect[1].F].y; 
	u.x = 1;
	u.y = 0;
	rect[1].S = rad(u, t); 
	t.x = pt[next(rect[2].F, n)].x - pt[rect[2].F].x;
	t.y = pt[next(rect[2].F, n)].y - pt[rect[2].F].y; 
	u.x = 0;
	u.y = 1;
	rect[2].S = rad(u, t); 
	t.x = pt[next(rect[3].F, n)].x - pt[rect[3].F].x;
	t.y = pt[next(rect[3].F, n)].y - pt[rect[3].F].y; 
	u.x = -1;
	u.y = 0;
	rect[3].S = rad(u, t); 
	double tot = 0, ma = DBL_MAX;
	while(tot <= 22.0/14.0){
		double mt = 0; 
		t.x = pt[rect[2].F].x - pt[rect[0].F].x;
		t.y = pt[rect[2].F].y - pt[rect[0].F].y;
		u.x = cos(tot);
		u.y = sin(tot);
		mt += 2 * abs(t.x * u.x + t.y * u.y);
		t.x = pt[rect[3].F].x - pt[rect[1].F].x;
		t.y = pt[rect[3].F].y - pt[rect[1].F].y;
		u.x = -sin(tot);
		u.y = cos(tot);
		mt += 2 * abs(t.x * u.x + t.y * u.y);
		if(mt < ma) ma = mt;
		double md = rect[0].S;
		for(int j = 1; j < 4; j++) if(rect[j].S < md) md = rect[j].S;
		for(int j = 0; j < 4; j++){
			rect[j].S -= md;
			if(!rect[j].S){
				int p = rect[j].F, q = next(p, n);
				t.x = pt[q].x - pt[p].x;
				t.y = pt[q].y - pt[p].y; 
				u.x = pt[next(q, n)].x - pt[q].x;
				u.y = pt[next(q, n)].y - pt[q].y;
				rect[j].F = q;
				rect[j].S = rad(t, u); 
			}
		}
		tot += md;
	}
	return ma;
}

int main(){
	int n;
	struct point p;
	while(scanf("%d", &n) > 0){
	hull.clear();
	for(int i = 0; i < n; i++){
		IN p.x; IN p.y;
		hull.PB(p);
	}
	m.y = m.x = DBL_MAX;
	n = convex_hull();
	cout << setprecision(20) << minAenclose(boundary, n) << "\n";
	}
	return 0;
}