#include <iostream>
#include <cstring>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 

using namespace std;

char s[100000];

long int find_inversion(int i, int j){
	char b[j - i + 1];
	if(i < j){
		int mid = (i + j)/2, p, q, r;
		long int c = 0;
		c = find_inversion(i, mid) + find_inversion(mid + 1, j);
		p = i;
		q = mid + 1;
		r = 0;
		while(p <= mid && q <= j) b[r++] = (s[p] <= s[q] ? s[p++] : ((c += mid - p + 1), s[q++]));
		while(p <= mid) b[r++] = s[p++];
		while(q <= j) b[r++] = s[q++];
		for(p = i; p <= j; p++)
			s[p] = b[p - i];
		return c;
	}
	else{
		return 0;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		IN s;
		OUT (find_inversion(0, strlen(s) - 1) > 0 ? "no" : "yes"); newline;
	} 
	return 0;
}