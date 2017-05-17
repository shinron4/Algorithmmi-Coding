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

int t[200001];

long int get(int i){
	long int sum = 0;
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

int search(int i, int j, int k){
	int mid; 
	while(i < j){
		mid = (i + j) >> 1;
		if(k <= get(mid)) j = mid;
		else i = mid + 1;
	}
	return i;
}

vector< pair<int, int> > a(200001);

int main(){
	fastIO
	int t, n;
	IN t;
	for(int i = 0; i < t; i++){
		IN n; 
		for(int j = 1; j <= n; j++){
			IN a[j].F;
			update(n, j, 1);
		}
		for(int j = n; j > 0; j--){
			int k;
			k = search(1, n, j - a[j].F);
			update(n, k, -1);
			a[j].S = k;
		}
		for(int j = 1; j <= n; j++){
			OUT a[j].S; space;
		}
		newline;
	}
	return 0;
}