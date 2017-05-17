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
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

struct node{
	int pre, suf, sum, max;
} a[100005];

void build(int n){
	int m, temp;
	for(int i = n - 1; i >= 1; i--){
		a[i].max = max(a[i << 1].max, a[i << 1 | 1].max);
		a[i].sum = a[i << 1].sum + a[i << 1 | 1].sum;
		temp = a[i << 1].sum + a[i << 1 | 1].pre;
		a[i].pre = max(a[i << 1].pre, temp);
		temp = a[i << 1].suf + a[i << 1 | 1].sum;
		a[i].suf = max(a[i << 1 | 1].suf, temp);
		if(a[i << 1].suf && a[i << 1 | 1].pre){
			temp = a[i << 1].suf + a[i << 1 | 1].pre;
			a[i].max = max(a[i].max, temp);
		}
	}
}

int query(int l, int r, int n){
	int i, j, m, k;
	struct node left, right;
	left.pre = left.suf = right.pre = right.suf = left.sum = right.sum = 0;
	left.max = right.max = -1000000;
	i = l + n - 1;
	j = r + n - 1;
	for(; i < j; i >>= 1, j >>= 1){
		if(i & 1){
			left.max = max(left.max, a[i].max);
			if(left.suf && a[i].pre){
				m = left.suf + a[i].pre;
				left.max = max(left.max, m);
			}
			m = left.sum + a[i].pre;
			left.pre = max(left.pre, m);
			m = left.suf + a[i].sum;
			left.suf = max(a[i].suf, m);
			left.sum += a[i].sum;
			i++;
		}
		if(j & 1){
			j--;
			right.max = max(right.max, a[j].max);
			if(a[j].suf && right.pre){
				m = a[j].suf + right.pre;
				right.max = max(right.max, m);
			}
			m = a[j].sum + right.pre;
			right.pre = max(a[j].pre, m);
			m = right.sum + a[j].suf;
			right.suf = max(right.suf, m);
			right.sum += a[j].sum;			
		}
	}
	m = max(left.max, right.max);
	if(left.suf && right.pre){
		k = left.suf + right.pre;
		m = max(m, k);
	}
	return m;
}

int main(){
	fastIO
	int n, m, x, l, r;
	IN n; 
	for(int i = n; i <= 2 * n - 1; i++){
		IN x;
		a[i].sum = a[i].max = x;
		a[i].pre = a[i].suf = (x > 0 ? x : 0);
	}
	build(n);
	IN m; 
	for(int i = 0; i < m; i++){
		IN l; IN r;
		OUT query(l, r + 1, n); newline;
	}
	return 0;
}