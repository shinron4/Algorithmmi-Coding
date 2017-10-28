#include <iostream>
#include <climits>

using namespace std;

int t[100001];

int get(int i){
	int sum = 0;
	while(i > 0){
		sum += t[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		t[i] += val;
		i += i & -i;
	}
}

int bsearch(int i, int j, int v){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(v <= get(mid)) j = mid;
		else i = mid + 1;
	}
	return i;
}

int st[2 * 100000];

void build(int a[], int n){
	for(int i = n; i < 2 * n; i++) st[i] = a[i - n];
	for(int i = n - 1; i > 0; i--){
		st[i] = max(st[i << 1], st[i << 1 | 1]);
	}
}

int query(int n, int l, int r){
	int res = -INT_MAX;
	for(l += n - 1, r += n - 1; l < r; l >>= 1, r >>= 1){
		if(l & 1) res = max(st[l++], res);
		if(r & 1) res = max(st[--r], res);
	}
	return res;
}

int main(){
	int n, q, a[100000];
	while(1){
		cin >> n;
		if(n == 0) break;
		cin >> q;
		int k = 0, x, y, f;
		cin >> x;
		f = 1;
		for(int i = 1; i < n; i++){
			cin >> y;
			if(x != y){
				a[k++] = f;
				f = 1; 
				x = y;
			}
			else f++;
		}
		a[k++] = f;		
		for(int i = 0; i < k; i++) update(k, i + 1, a[i]);
		build(a, k);
		for(int i = 0; i < q; i++){
			int p, q, l, r, ma = -1;
			cin >> p >> q;
			l = bsearch(1, k, p);
			r = bsearch(1, k, q);
			if(l == r) ma = q - p + 1;
			else ma = max(get(l) - p + 1, q - get(r - 1));
			if(r - l - 1 > 0) ma = max(ma, query(k, l + 1, r));
			cout << ma;
			cout << "\n";
		}
		for(int i = 1; i <= k; i++) t[i] = 0;
	}
}