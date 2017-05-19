#include <iostream>
#include <cstring>

#define convert(n) n - '0'

using namespace std;


int main(){
	char P[20];
	int N[20], T, j, k, min = 9;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> P;
		j = strlen(P);
		for(k = 0; k < j; k++)
			N[k] = convert(P[k]);
		k = 0;
		while(k < j - 1 && N[k] <= N[k + 1]) k++;
		if(k < j - 1){
			N[k]--;
			while(k > 0 && N[k - 1] > N[k]){
				N[k - 1]--;
				k--;
			}
			k++;
			while(k < j){
				N[k] = 9;
				k++;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		k = 0;
		while (N[k] == 0) k++;
		for(; k < j; k++)
			cout << N[k];
		cout << "\n";
	}
	return 0;
}