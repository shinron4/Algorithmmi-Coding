#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> l;

int main(){
	int T, N, x, j, flag;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N;
		for(int k = 0; k < N; k++){
			cin >> x;
			l.push_back(x);
		}
		sort(l.begin(), l.end());
		j = l.size() - 3;
		flag = 0;
		while(j >= 0){
			if(l[j] + l[j + 1] > l[j + 2]){
				flag = 1;
				break;
			}
			j--;
		}
		if(flag == 0){
			cout << -1 << "\n";
		}
		else{
			cout << l[j] << " " << l[j + 1] << " " << l[j + 2] << "\n";
		}
		l.clear();
	}
	return 0;
}