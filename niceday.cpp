#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>

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

struct rnk{
	int f, s, t;
} r[100001];

bool compare(const struct rnk &a, const struct rnk &b){
	return a.f < b.f;
}

int t[100001];

int max(const int &a, const int &b){
	return a > b ? a : b;
}

int get(int i){
	int m = 0;
	while(i > 0){
		m = max(m, t[i]);
		i -= i & -i;
	}
	return m;
}

void update(int n, int i, int val){
	while(i <= n){
		t[i] = max(t[i], val);
		i += i & -i;
	}
}

int main(){
	fastIO
	int test;
	IN test;
	LPA(int, i, test){
		int n, cnt = 0;
		IN n;
		LP(int, j, 1, n, 1){
			IN r[j].f; IN r[j].s; IN r[j].t;
		}
		sort(r + 1, r + n + 1, compare);
		LP(int, j, 1, n, 1){
			if(get(r[j].s) < 2 * n + 1 - r[j].t) cnt++;
			update(n, r[j].s, 2 * n + 1 - r[j].t);
		}
		OUT cnt; newline;
		LP(int, j, 1, n, 1) t[j] = 0;
	}
	return 0;
}