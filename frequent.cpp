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

using namespace std;

int a[100001];

int get(int i){
	int sum = 0; 
	while(i > 0){
		sum += a[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		a[i] += val;
		i += i & -i;
	}
}

vector< pair<int, int> > t(2 * 100000), ft;

void build(int n){
	for(int i = n - 1; i > 0; i--) t[i] = t[i << 1].F > t[i << 1 | 1].F ? t[i << 1] : t[i << 1 | 1];
}

int query(int n, int l, int r){
	int lmax, rmax;
	lmax = rmax = -1;
	for(l += n - 1, r += n - 1; l < r; l >>= 1, r >>= 1){
		if(l & 1){
			lmax = t[l].F > lmax ? t[l].F : lmax;
			l++;
		}
		if(r & 1){
			r--;
			rmax = t[r].F > rmax ? t[r].F : rmax;
		}
	}
	return rmax > lmax ? rmax : lmax;
}

int main(){
	fastIO
	int n, q, x, y, z, f, f2;
	while(1){
		IN n;
		if(!n) break;
		IN q;
		x = -1000000;
		f = 1;
		z = 0;
		for(int j = 1; j <= n; j++){
			IN y;
			if(x != y){
				ft.PB(MP(f, z));
				f = 1;
				update(n, j, 1);
				x = y;
				z = j;
			}
			else f++;
		}
		ft.PB(MP(f, z));
		for(int j = z = ft.size() - 1; j <= 2 * z - 1; j++) t[j] = ft[j - z + 1];
		build(z);
		for(int j = 0; j < q; j++){
			int l, r;
			IN x; IN y;
			l = get(x);
			r = get(y);
			if(l < r){
				f = query(z, l + 1, r);
				f2 = ft[l].S + ft[l].F - x;
				f = f2 > f ? f2 : f;
				f2 = y - ft[r].S + 1;
				f = f2 > f ? f2 : f;
				OUT f;
			}
			else{
				OUT y - x + 1;
			}
			newline;
		}
		for(int j = 1; j < ft.size(); j++) update(n, ft[j].S, -1);
		ft.clear();
	}
	return 0;
}