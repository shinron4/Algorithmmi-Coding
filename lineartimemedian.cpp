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
#define mid(a, l, r) (sort(a.begin() + l, a.begin() + r + 1), a[(l + r)/2])

using namespace std;

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int select(vector<int> &a, int l, int r, int k){
	if(l < r){
		int g = (r - l)/5 + 1;
		vector<int> m(g);
		for(int i = 0; i < g; i++){
			int p = l + i * 5, q = p + 4 > r ? r : p + 4;
			m[i] = mid(a, p, q);
		}
		int mom = select(m, 0, m.size() - 1, (m.size() - 1)/2);
		int p = l - 1;
		for(int i = l; i <= r; i++)
			if(a[i] <= mom){
				p++;
				swap(a[p], a[i]);
			}
		if(p == k) return a[k];
		else if(k < p) return select(a, l, p - 1, k);
		else return select(a, p + 1, r, k);
	}
	else
		return a[l];
} 

vector<int> a(100000), b(100000);

int main(){
	int t, maxm, m;
	IN t;
	for(int i = 0; i < t; i++){
		int n;
		IN n;
		for(int j = 0; j < 2 * n; j++){
			IN a[j];
		}
		m = select(a, 0, 2 * n - 1, n - 1);
		int p = -1;
		for(int j = 0; j <= 2 * n - 1; j++){
			if(a[j] <= m){
				p++;
				swap(a[p], a[i]);
			}
		}
		maxm = select(a, n, 2 * n - 1, n + n/2);
		OUT maxm; newline;
		p = 0;
		for(int i = 0; i < 2 * n; i += 2){
			b[i] = a[p++];
		}
		for(int i = 1; i < 2 * n; i += 2){
			b[i] = a[p++];
		}
		for(int i = 0; i < 2 * n; i++){
			OUT b[i]; space;
		}
		newline;
	}
	return 0;
}