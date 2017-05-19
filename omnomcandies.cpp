#include <iostream>

using namespace std;

long int c[100005];

int main(){
	int N , a[100005];
	long int sum;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
		if(i == 1)
			c[i] = a[i];
		else
			c[i] = a[i] + a[1];
	}
	for(int i = 2; i <= N; i++){
		sum = c[i];
		for(int j = 2; j * i <= N; j++){
			if(c[j * i] < c[i] + a[j * i])
				c[j * i] = c[i] + a[j * i];
		}
	}
	for(int i = 1; i <= N; i++)
		cout << c[i] << " ";
	return 0;
}