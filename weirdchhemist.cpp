#include <iostream>
using namespace std;
int main(){
	int M, N, l, r, count = 0;
	long int a[10005], x;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	for(int i = 1; i < N; i++)
		a[i] += a[i - 1];
	for(int i = 0; i < M; i++){
		cin >> l >> r >> x;
		if(l > 1){
			if(a[r - 1] - a[l - 2] >= x)
				count++;
		}
		else{
			if(a[r - 1] >= x)
				count++;
		}
	}
	cout << count;
	return 0;
}