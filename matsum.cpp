#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>
#include <string>

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

struct val{
	long long int o, n;
} a[1024][1024];

long long int c[1025][1025], u, v, w;

long long int get(int i, int j){
	long long int sum = 0;
	int x, y;
	x = i;
	while(x > 0){
		y = j;
		while(y > 0){
			sum += c[x][y];
			y -= y & -y;
		}
		x -= x & -x;
	}
	return sum;
}

void update(int i, int j, int n, long long int val){
	int x, y;
	x = i;
	while(x <= n){
		y = j;
		while(y <= n){
			 c[x][y] += val;
			y += y & -y;
		}
		x += x & -x;
	}
}

vector< pair<int, int> > setq;

int main(){
	int t, n, x, y, p , q, k;
	long long int sum;
	char s[3];
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		k = 0;
		do{
			scanf("%s", s);
			switch(s[1]){
				case 'E' : 
					scanf("%d%d%lld", &x, &y, &sum);
					a[x][y].n = sum;
					setq.PB(MP(x, y));
					break;
				case 'U' :
					for(int j = k; j < setq.size(); j++){
						//OUT setq[j].F + 1; space; OUT setq[j].S + 1; space; OUT a[setq[j].F][setq[j].S].n - a[setq[j].F][setq[j].S].o; newline;
						update(setq[j].F + 1, setq[j].S + 1, n, a[setq[j].F][setq[j].S].n - a[setq[j].F][setq[j].S].o);
						a[setq[j].F][setq[j].S].o = a[setq[j].F][setq[j].S].n;
					}
					k = setq.size();
					scanf("%d%d%d%d", &x, &y, &p, &q);
					w = get(p + 1, q + 1);
					u = x > 0 ? get(x, q + 1) : 0;
					v = y > 0 ? get(p + 1, y) : 0;
					printf("%lld\n", w - (u + v) + (x > 0 && y > 0 ? get(x, y) : 0));
					break;
				case 'N' :
					sort(setq.begin(), setq.begin() + k);
					for(int j = 1; j < k; j++){
						if(setq[j] != setq[j - 1]){
							update(setq[j - 1].F + 1, setq[j - 1].S + 1, n, -a[setq[j - 1].F][setq[j - 1].S].o);
							a[setq[j - 1].F][setq[j - 1].S].o = 0;
						}
					}
					update(setq[k - 1].F + 1, setq[k - 1].S + 1, n, -a[setq[k - 1].F][setq[k - 1].S].o);
					a[setq[k - 1].F][setq[k - 1].S].o = 0;
					setq.clear();
					printf("\n");
					break;
			}
		}while(s[1] != 'N');
	}
	return 0;
}