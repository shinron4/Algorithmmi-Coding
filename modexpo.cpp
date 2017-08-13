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

int fastmod(int a, int x, int n){
	int l = 1 << (int)floor(log2(x)); 
	long long int t = 1;
	while(l > 0){
		t = (t * t) % n;
		if(x & l) t = (t * a) % n;
		l >>= 1;
	}
	return t;
}

int main(){
	int n, c;
	IN n;
	c = fastmod(3, n, 1000000006);
	OUT fastmod(3, c, 1000000007); newline;
	return 0;
}