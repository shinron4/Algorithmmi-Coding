#include <iostream>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
using namespace std;

long int c[10005];

long int get(int i){
	long int sum = 0;
	while(i > 0){
		sum += c[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		c[i] += val;
		i += i & -i;
	}
}

int main(){
	int t, n, u, q, l, r, v, idx;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d%d", &n, &u);
		for(int j = 0; j < u; j++){
			scanf("%d%d%d", &l, &r, &v);
			update(n, l + 1, v);
			update(n, r + 2, -v);
		}
		scanf("%d", &q);
		for(int j = 0; j < q; j++){
			scanf("%d", &idx);
			printf("%ld\n", get(idx + 1));
		}
		for(int i = 0; i <= n; i++)
			c[i] = 0;
	}
	return 0;
}