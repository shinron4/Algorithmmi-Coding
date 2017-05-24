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

using namespace std;

class compare{
	public : 
		bool operator() (const long long int &a, const long long int &b){
			return a < b;
		}
};

priority_queue< long long int, vector<long long int>, compare > q;

vector< pair<long long int, long long int> > a(10001);

int main(){
	fastIO
	long long int t, n, p, l;
	IN t;
	LPA(long long int, i, t){
		IN n;
		for(long long int j = 1; j <= n; j++){
			IN a[j].F; IN a[j].S;
		}
		IN l; IN p;
		for(long long int j = 1; j <= n; j++) a[j].F = l - a[j].F;
		sort(a.begin() + 1, a.begin() + n + 1);
		int k = 1, cnt = 0;
		while(k <= n && a[k].F <= p) q.push(a[k++].S);
		while(!q.empty() && p < l){
			p += q.top();
			q.pop();
			cnt++;
			while(k <= n && a[k].F <= p) q.push(a[k++].S);
		}
		OUT (p < l ? -1 : cnt); newline;
		while(!q.empty()) q.pop();
	}
	return 0;
}