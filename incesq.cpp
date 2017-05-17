#include <iostream>
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

using namespace std;

long int dp[10001][51];
vector<int> a(10001), b;
vector< int > c;

int mod(int b, int m){
	while( b < 0) b += m;
	while(b >= m) b -= m;
	return b;
}

long int get(int i, int j){
	long int sum = 0;
	int x, y;
	x = i;
	while(x > 0){
		y = j;
		while(y > 0){
			sum = (sum + dp[x][y]) % 5000000;
			y -= y & -y;
		}
		x -= x & -x;
	}
	return sum;
}

void update(int n, int m, int i, int j, long int val){
	int x, y;
	x = i;
	while(x <= n){
		y = j;
		while(y <= m){
			dp[x][y] = (dp[x][y] + val) % 5000000;
			y += y & -y;
		}
		x += x & -x;
	}
}

int search(int i, int j, int k){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(k <= c[mid]) j = mid;
		else i = mid + 1;
	}
	return i;
}

int main(){
	fastIO
	int n, k;
	long int sum = 0;
	IN n; IN k; 
	for(int i = 1; i <= n; i++){
		IN a[i];
		b.PB(a[i]);
	}
	sort(b.begin(), b.end());
	c.PB(b[0]);
	for(int i = 1; i < b.size(); i++) if(b[i] != b[i - 1]) c.PB(b[i]);
	for(int i = 1; i <= n; i++){
		 int idx = search(0, c.size() - 1, a[i]) + 1;
		for(int j = 1; j <= k; j++){
			if(j == 1) sum = 1;
			else if(idx != 1) sum = mod(get(idx - 1, j - 1) - (j - 1 > 1 ? get(idx - 1, j - 2) : 0), 5000000);
			else sum = 0;
			update(c.size(), k, idx, j, sum);
		}
	}
	OUT mod(get(c.size(), k) - (k - 1 >= 1 ? get(c.size(), k - 1) : 0), 5000000); newline;
	return 0;
}
