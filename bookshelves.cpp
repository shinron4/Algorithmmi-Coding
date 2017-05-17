#include <iostream>
#include <vector>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "

using namespace std; 

vector <int> s1, s2; 

int main(){
	int n, x, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> x;
		s1.PB(x);
	}
	for(int i = 0; i < n; i++){
		cin >> x;
		s2.PB(x);
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if(s1[s1.size() - 1] <= s2[s2.size() - 1]){
		int i = s1.size() - 1, j = 0, l = 0;
		while(l < k && s1[i] >= s2[j]){
			l++; i--; j++;
		}
		if(s1[i] >= s2[j]){
			cout << s2[s2.size() - 1] + s1[i]; newline;
		}
		else{
			cout << s2[s2.size() - 1] + (j > 0 ? s2[j - 1] : s1[s1.size() - 1]); newline;
		}
	}
	else{
		int i = s2.size() - 1, j = 0, l = 0;
		while(l < k && s2[i] >= s1[j]){
			l++; i--; j++;
		}		
		if(s2[i] >= s1[j]){
			cout << s1[s1.size() - 1] + s2[i]; newline;
		}
		else{
			cout << s1[s1.size() - 1] + (j > 0 ? s1[j - 1] : s2[s2.size() - 1]); newline;
		}
	}
	return 0;
}