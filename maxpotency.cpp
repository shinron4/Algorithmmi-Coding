#include <iostream>
#include <algorithm>
#include <vector>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "

using namespace std;

int w[1 << 15], p[1 << 15];
 
vector< int > e;

int main(){
	int n, v;
	while(scanf("%d",&n) > 0){
		v = 1 << n;
		for(int i = 0; i < v; i++){
			cin >> w[i];
		}
		for(int i = 0; i < v; i++){
			int mask = 1 << (n - 1);
			p[i] = 0;
			while(mask > 0){
				p[i] += w[i ^ mask];
				mask >>= 1;
			}
		}
		for(int i = 0; i < v; i++){
			int mask = 1 << (n - 1);
			while(mask > 0){
				e.PB(p[i] + p[i ^ mask]);
				mask >>= 1;
			}
		}
		sort(e.begin(), e.end());
		cout << e[e.size() - 1]; newline;
		e.clear();
	}
	return 0;
}