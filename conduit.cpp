#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <complex>
#include <cassert>

using namespace std;

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define OUT cout << 
#define IN cin >> 
#define newline cout << "\n"
#define space cout << " "
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define smaller(a, b) (a.x < b.x || (a.x == b.x && a.y < b.y))


const double EPSILON = 1e-9;

struct point{
	double x, y;
};

struct segment{
	struct point p, q;
	double m;
};

void swap(struct point &p1, struct point &p2){
	struct point t;
	t = p1;
	p1 = p2; 
	p2 = t;
}

double area(const struct point &p1, const struct point &p2, const struct point &p3){
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

struct COMP{
	bool operator() (const struct segment &s1, const struct segment &s2){
		if(fabs(s1.m - s2.m) > EPSILON) return s1.m < s2.m;
		double a = area(s1.p, s1.q, s2.p);
		if(fabs(a) > EPSILON) return a < 0;
		else return smaller(s1.p, s2.p);
	}
} compare;

vector<struct segment> vs;

int main(){
	while(1){
		int n;
		IN n;
		if(!n) break;
		vs.clear();
		for(int j = 0; j < n; j++){
			struct segment l;
			IN l.p.x; IN l.p.y;
			IN l.q.x; IN l.q.y;
			if(smaller(l.q, l.p)) swap(l.p, l.q);
			l.m = atan2(l.q.y - l.p.y, l.q.x - l.p.x);
			vs.PB(l);
		}
		sort(vs.begin(), vs.end(), compare);
		int count = 1;
		struct segment span = vs[0];
		for(int j = 1; j < n; j++){
			if(fabs(span.m - vs[j].m) < EPSILON && fabs(area(span.p, span.q, vs[j].p)) < EPSILON){
				if(!smaller(span.q, vs[j].p)){
					if(smaller(span.q, vs[j].q)) span.q = vs[j].q;
				}
				else{
					span = vs[j];
					count++;
				}
			}
			else{
				span = vs[j];
				count++;
			}
		}
		OUT count; newline;
	}
	return 0;
}