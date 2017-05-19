#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char S[100005];
	int T, s, j, k, t;
	long long int count;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> S;
		s = strlen(S);
		j = 0;
		count = 0;
		while(j < s && S[j] == '0') j++;
		k = j;
		while(k < s){
			if(S[k] == '1'){
				k++;
				continue;
			}
			t = k--;
			while(t < s && S[t] == '0') t++;
			t--;
			count += (t - k + 1) * (k - j + 1);
			j += t - k;
			k = t + 1;
		}
		cout << count << "\n";
	}
	return 0;
}