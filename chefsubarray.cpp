#include <iostream>
#include <cmath> 
#include <queue>
#include <map>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
using namespace std;

char a[100000];

map <int, int>f;
queue <int> sets;

int main(){
	int n, k, p, c = 0, max = 0;
	int i, j, l, r;
	IN n; IN k; IN p;
	for(int i = 0; i < n; i++)
		IN a[i];
	for(i = n - k; i < n; i++) if(a[i] == '1') c++;
	j = n - 1;
	i = n - k;
	while (i >= 0){
		sets.push(c);
		if(f.count(c) > 0) f[c] = f[c] + 1;
		else f[c] = 1;
		if(a[j] == '1') c--;
		j--; i--;
		if(i >= 0 && a[i] == '1') c++;
	}
	l = 0;
	r = n - 1;
	for(int i = 0; i < p; i++){
		char x;
		cin >> x;
		if(x == '!'){
			c = sets.front();
			f[c] = f[c] - 1;
			if(f[c] == 0) f.erase(c);
			sets.pop();
			int t = sets.back();
			if(a[(l + k - 1) % n] == '1') t--;
			if(a[r] == '1') t++;
			if(f.count(t) > 0){
				f[t] = f[t] + 1;
			}
			else{
				f[t] = 1;
			}
			sets.push(t);
			l = l <= 0 ? n - 1 : --l;
			r = r <= 0 ? n - 1 : --r;
		}
		else{
			map<int,int>::iterator it=f.end();
			OUT (--it)->first; newline;
		}
 	}
 	return 0;
}