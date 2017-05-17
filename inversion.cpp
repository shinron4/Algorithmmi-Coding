#include <iostream>
using namespace std;

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 

int a[200005];

long int find_inversion(int i, int j){
	int b[j - i + 1];
	if(i < j){
		int mid = (i + j)/2, p, q, r;
		long int c = 0;
		c = find_inversion(i, mid) + find_inversion(mid + 1, j);
		p = i;
		q = mid + 1;
		r = 0;
		while(p <= mid && q <= j){
			if(a[p] <= a[q]){
				b[r] = a[p];
				p++;			
			}
			else{
				c += mid - p + 1;
				b[r] = a[q];
				q++;
			}
			r++;
		}
		while(p <= mid) b[r++] = a[p++];
		while(q <= j) b[r++] = a[q++];
		OUT i; space; OUT j; newline;
		for(p = i; p <= j; p++){
			a[p] = b[p - i];
			OUT a[p]; space;
		}
		newline;
		return c;
	}
	else{
		return 0;
	}
}

int main() {
	int t, n;
	IN t;
	for(int j = 0; j < t; j++){
		IN n;
		for(int i = 0; i < n; i++){
			IN a[i];
		}
		OUT find_inversion(0, n - 1); newline;
	}
	return 0;
}