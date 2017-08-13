#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <climits>
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
#define smaller(a, b) (a.x < b.x || (a.x == b.x && a.y < b.y))
#define dist(p, q) (sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y)))
#define area(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x))
using namespace std;

struct point{
	int x, y;
};

struct point m = {INT_MAX, INT_MAX};

struct{
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

double polygonDiameter(vector<struct point> &p, int n)
{
    if(n<2) return 0;
    else if(n==2) return dist(p[0],p[1]);//distance between two points
    else
    {
        int i=n-1,j=0,k=1, s_p, s_q;
        double m=0, d;
        while(abs(area(p[i], p[j], p[k+1])) > abs(area(p[i], p[j], p[k])))
        {
            k++;
        }
        i=0,j=k;
        while(i<=k && j<n)
        {
			if((d = dist(p[i], p[j])) > m){
				m = d;
				s_p = i;
				s_q = j;
			}        	
            while(j<n-1 && abs(area(p[i], p[i + 1], p[j+1])) > abs(area(p[i], p[i + 1], p[j])))
            {
                j++;
				if((d = dist(p[i], p[j])) > m){
					m = d;
					s_p = i;
					s_q = j;
				}        	
            }
            i++;
        }
        return dist(p[s_p], p[s_q]);
    }
}

int main(){
	fastIO
	int n;
	float m = -1, d;
	struct point p;
	IN n;
	for(int i = 0; i < n; i++){
		IN p.x; IN p.y;
		hull.PB(p);
	}
	n = convex_hull();
	// 	for(int i = 0; i < n; i++){
	// 	OUT boundary[i].x; space; OUT boundary[i].y; newline;
	// }
	cout << setprecision(20) << polygonDiameter(boundary, n);
	return 0;
}