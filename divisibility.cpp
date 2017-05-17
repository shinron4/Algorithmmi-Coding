#include <iostream>

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

int mod(int n, int k){
	int t = n % k;
	return t < 0 ? t + k : t;
}

char a[10000][100];

int num[10000];

int main(){
	fastIO
	int t, n, k;
	IN t;
	for(int i = 0; i < t; i++){
		IN n; IN k;
		for(int j = 0; j < n; j++) IN num[j];
		a[0][mod(num[0], k)] = '1';
		for(int p = 1; p < n; p++)
			for(int q = 0; q < k; q++)
				if(a[p - 1][q] == '1'){
					a[p][mod(q + num[p], k)] = '1';
					a[p][mod(q - num[p], k)] = '1';
					a[p - 1][q] = '0';
				}
		OUT (a[n - 1][0] == '1' ? "Divisible" : "Not divisible"); newline;
		for(int q = 0; q < k; q++) a[n - 1][q] = '0';
	}
	return 0;
}