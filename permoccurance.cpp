#include <iostream>
#include <cstring>

using namespace std;

char W[3000], S[3000000];
long int lcount[26], ucount[26], w, s, occ_count;

int main(){
	cin >> w >> s >> W >> S;
	for(int i = 0; i < w; i++)
		if(W[i] >= 'A' && W[i] <= 'Z') ucount[W[i] - 'A'] += 1;
		else lcount[W[i] - 'a'] += 1;
	int i, k, l;
	l = i = k = 0;
	while(i < s){
		while(k < w){
			if(S[i] >= 'A' && S[i] <= 'Z'){
				if(ucount[S[i] - 'A'] == 0) break;
				else ucount[S[i] - 'A'] -= 1;
			}
			else{
				if(lcount[S[i] - 'a'] == 0) break;
				else lcount[S[i] - 'a'] -= 1;
			}
			k++;
			i++;
		}
		if(k == w) occ_count++;
		while(l < i){
			if(S[l] >= 'A' && S[l] <= 'Z'){
				ucount[S[l] - 'A'] += 1;										
				if(ucount[S[i] - 'A'] > 0){
					k = i - l - 1;
					break;
				}
			}
			else{
				lcount[S[l] - 'a'] += 1;
				if(lcount[S[i] - 'a'] > 0){
					k = i - l - 1;
					break;
				}
			}
			l++;
		}
		if(i == l){
			l = ++i;
			k = 0;
		}
	}
	cout << occ_count << "\n";
	return 0;
}