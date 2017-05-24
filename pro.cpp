#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <map>

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

map<int, int> mp;

int main(){
	fastIO
	int n, k, x, max, min; 
	long int cnt = 0;
	IN n;
	for(int i = 0; i < n; i++){
		IN k;
		for(int j = 0; j < k; j++){
			IN x;
			mp[x] =  mp.count(x) > 0 ? mp[x] + 1 : 1;
		}
		min = (mp.begin())->F;
		max = (--mp.end())->F;
		cnt += max - min;
		if(mp[min] == 1) mp.erase(min);
		else mp[min]--;
		if(mp[max] == 1) mp.erase(max);
		else mp[max]--;
	}
	OUT cnt; newline;
	return 0;
}