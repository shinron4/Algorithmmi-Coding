#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int prime[1000001];
vector<int> p;

int main(){
	for(int i = 2; i <= 1000000; i++)
		if(!prime[i]){
			p.push_back(i);
			for(int j = 2; j * i <= 1000000; j++)
				prime[j * i] = 1;
		}
	int T , N, power, temp;
	long int sum, i;
	cin >> T;
	for(int j = 0; j < T; j++){
		cin >> N;
		i = 0;
		sum = 1;
		temp = N;
		while(p[i] <= temp){
			power = 0;
			while(temp % p[i] == 0){
				temp /= p[i];
				power++;
			}
			sum *= ((int)pow(p[i], power + 1) - 1)/(p[i] - 1);
			i++;
		}
		cout << (sum == 2 * N ? "YES" : "NO") << "\n";
	}
	return 0;
}
