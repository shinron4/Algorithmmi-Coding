#include <iostream>
#include <cmath>
#include <climits>


#define MOD 1000000007
#define P 101
#define space cout << " ";
#define newline cout << "\n";

using namespace std;

unsigned long long int suffix[100000], prefix[100000], power[100000];
int n;
string s;

int sqremult(int a, int x, int m){
	int l = (int)floor(log2(x)), mask = 1 << l;
	long long int t = 1;
	while(mask > 0){
		t = (t * t) % m;
		if(int(x & mask) != 0){
			t = (t * a) % m;
		}
		mask >>= 1;
	}
	return t;
}

bool checkPalindrome(int l, int r){
	while(l < r){
		if(s[l++] != s[r--])
			return false; 
	}
	return true;
}

int hsh(int l, int r){
	return ((prefix[r] - (l > 0 ? prefix[l - 1] : 0)) * sqremult(P, MOD - 1 - l, MOD)) % MOD;
}

int reverse_hsh(int l, int r){
	return ((suffix[l] - (r < n - 1 ? suffix[r + 1] : 0)) * sqremult(P, MOD - n + r, MOD)) % MOD;
}

int main(){
	int q, c, l, r;
	cin >> n >> q >> s;
	/*power[0] = 1;
	for(int i = 1; i < n; i++){
		power[i] = (power[i - 1] * P) % MOD;
	}
	prefix[0] = s[0] - 'a';
	suffix[n - 1] = s[n - 1] - 'a';
	for(int i = 1; i < n; i++){
		prefix[i] = (prefix[i - 1]%MOD + (power[i]%MOD * (s[i] - 'a')%MOD)%MOD)%MOD;
		suffix[n - 1 - i] = (suffix[n - i]%MOD + (power[i]%MOD * (s[n - i - 1] - 'a')%MOD)%MOD)%MOD;  
	}*/
	for(int t = 0; t < q; t++){
		cin >> c;
		if(c == 0){
			int l; char r;
			cin >> l >> r;
			l--;
			/*for(int j = 0; j < n; j++)
				if( j < l)
					suffix[j] = (suffix[j] % MOD + ((r - s[l]) * power[n - 1 - l] % MOD) % MOD) % MOD;
				else if(j == l){
					suffix[j] = (suffix[j] % MOD + ((r - s[l]) * power[n - 1 - l] % MOD) % MOD) % MOD;
					prefix[j] = (prefix[j] % MOD + ((r - s[l]) * power[l] % MOD) % MOD) % MOD; 
				}
				else
					prefix[j] = (prefix[j] % MOD + ((r - s[l]) * power[l] % MOD) % MOD) % MOD; */
			s[l] = r;			
		}
		else{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			/*if(hsh(l, r) != reverse_hsh(l, r))
				cout << "No" << "\n";
			else*/
				cout << (checkPalindrome(l, r) == true ? "Yes" : "No") << "\n";	
		}

	}
	return 0;
} 