#include <iostream>
#include <algorithm>

using namespace std;

bool isvalid(int a[], int n, int k, int d){
	int l = 0, i = 1;
	k--;
	while(k > 0){
		int j = n - 1, mid;
		if(i > j) break;
		while(i < j){
			mid = (i + j) >> 1;
			if(d <= a[mid] - a[l]) j = mid;
			else i = mid + 1; 
		}
		if(d > a[i] - a[l]) break;
		k--;
		l = i; 
		i++;
	}
	return k == 0;
}

int main(){
	int t, n, k, a[100000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++) cin >> a[j];
		sort(a, a + n);

		int p = 1, q = a[n - 1] - a[0], mid;
		while(p < q){
			mid = (p + q) >> 1;
			if(isvalid(a, n, k, mid)) p = mid + 1;
			else q = mid;
		}
		if(isvalid(a, n, k, p)) cout << p << "\n";
		else cout << p - 1 << "\n";
	}
	return 0;
}