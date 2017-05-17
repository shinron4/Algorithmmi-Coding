#include <iostream>
#include <map>
#include <string>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
using namespace std;

map <string, int> mp;
int a[300000];

long int find_inversion(int i, int j){
	int b[j - i + 1];
	if(i < j){
		int mid = (i + j)/2, p, q, r;
		long int c = 0;
		c = find_inversion(i, mid) + find_inversion(mid + 1, j);
		p = i;
		q = mid + 1;
		r = 0;
		while(p <= mid && q <= j) b[r++] = (a[p] <= a[q] ? a[p++] : ((c += mid - p + 1), a[q++]));
		while(p <= mid) b[r++] = a[p++];
		while(q <= j) b[r++] = a[q++];
		for(p = i; p <= j; p++)
			a[p] = b[p - i];
		return c;
	}
	else{
		return 0;
	}
}

int main(){
	int t, n;
	string s, y[300000];
	IN t;
	for(int i = 0;i < t; i++){
		IN n;
		for(int j = 0; j < n; j++) IN y[j];
		for(int j = 0; j < n; j++){
			IN s;
			mp[s] = j;
		}
		for(int j = 0; j < n; j++) a[j] = mp[y[j]];
		OUT find_inversion(0, n - 1); newline;
		mp.clear();
	}
	return 0;
}