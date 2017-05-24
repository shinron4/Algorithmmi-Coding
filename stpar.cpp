#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <stack>

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

stack<int> s;

vector<int> a(1000);

int main(){
	int n;
	s.push(10000);
	while(1){
		IN n;
		if(!n) break;
		int x, k = 0, i;
		for(i = 0; i < n; i++){
			IN x;
			while(x > s.top()){
				a[k++] = s.top();
				s.pop();
			}
			s.push(x);
		}
		x = 10000;
		while(x > s.top()){
			a[k++] = s.top(); 
			s.pop();
		}
		for(i = 1; i < k; i++) if(a[i] < a[i - 1]) break;
		OUT (i < k ? "no" : "yes"); newline;
	}
	return 0;
}