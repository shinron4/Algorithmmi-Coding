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

using namespace std;

int prefix[100005], minprefix[100005],sum;

int main(){
	int t, n, a[100005];
	IN t;
	for(int i = 0; i < t; i++){
		IN n;
		prefix[0] = 0;
		minprefix[0] = 0;
		for(int j = 1; j < n; j++){
			IN a[j];
			prefix[j] = prefix[j - 1] + a[j];
			minprefix[j] = prefix[j] < prefix[minprefix[j - 1]] ? j : minprefix[j - 1];
		}
		int p, q;
		p = q = 0;
		sum = -100000000;
		for(int j = 1; j < n; j++){
			int d = prefix[j - 1] - prefix[minprefix[j - 1]] + a[j];
			if(sum < d || (sum == d && j - minprefix[j - 1] > q - p + 1)){
				sum = d;
				p = minprefix[j - 1] + 1;
				q = j;
			}
		}
		if(sum >= 0){
			printf("The nicest part of route %d is between stops %d and %d\n", i + 1, p, q + 1);
		}
		else{
			printf("Route %d has no nice parts\n", i + 1);
		}
	}
	return 0;
}