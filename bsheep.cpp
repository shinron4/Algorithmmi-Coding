#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <iomanip>
#include <climits>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define P struct point
#define VP vector<struct point>
#define smaller(a, b) (a.y < b.y || (a.y == b.y && a.x < b.x))

using namespace std;


struct point{
	int x, y;
};

int area(const P &p1, const P &p2, const P &p3){
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

double dist(const P &p, const P &q){
	return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}

P m;
struct COMP{
	bool operator()(const pair<P, int> &a, const pair<P, int> &b){
		int A = area(m, a.F, b.F);
		if(A > 0) return true;
		else if(!A) return smaller(a.F, b.F);
		else return false;
	}
} compare;

vector< pair<P, int> > hull, boundary(1000000);

int convex_hull(){
	int n = hull.size();
	if(n == 0) return 0;
	for(int i = 0; i < n; i++) if(smaller(hull[i].F, m)) m = hull[i].F;
	sort(hull.begin(), hull.end(), compare);
	for(int i = 0; i < n - 1; i++){
		if(hull[i].F.x == hull[i + 1].F.x && hull[i].F.y == hull[i + 1].F.y){
			hull[i + 1].S = hull[i].S;
		}
	}
	stack< pair<P, int> > S;
	S.push(hull[0]);
	if(n > 1){
		S.push(hull[1]);
		for(int i = 2; i < n; i++){
			pair<P, int> u = S.top();
			S.pop();
			while(!S.empty() && area(S.top().F, u.F, hull[i].F) <= 0){
				u = S.top();
				S.pop();
			}
			S.push(u);
			S.push(hull[i]);
		}
	}
	int i = (n = S.size()) - 1;
	while(!S.empty()){
		boundary[i--] = S.top();
		S.pop();
	}
	return n;
}


int main(){
	int t, n;
	P p;
	IN t;
	for(int i = 0; i < t; i++){
		hull.clear();
		IN n;
		for(int j = 0; j < n; j++){
			IN p.x; IN p.y;
			hull.PB(MP(p, j));
		}
		m.y = (m.x = INT_MAX, INT_MAX);
		n = convex_hull();
		if(n > 0){
			double A = 0;
			for(int j = 0; j < n - 1; j++) A += dist(boundary[j].F, boundary[j + 1].F);
			A += dist(boundary[n - 1].F, boundary[0].F);
			cout << setprecision (2) << fixed << A; newline;
			for(int j = 0; j < n; j++){
				OUT (boundary[j].S + 1); space;
			}
			newline;
		}
	}
	return 0;
}