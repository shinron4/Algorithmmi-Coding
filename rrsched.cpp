#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector< pair<long long int, int> > task(50001);

vector< pair<long long int, vector<int> > > uni(50001);

int t[50001];
long long int a[50001];

long long int get(int i){
	long long int sum = 0;
	while(i > 0){
		sum += t[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		t[i] += val;
		i += i & -i;
	}
}

int main(){
	int n, k = 0;
	IN n;
	for(int i = 1; i <= n; i++){
		IN task[i].F;
		task[i].S = i;
		update(n, i, 1);
	}
	sort(task.begin() + 1, task.begin() + n + 1);
	for(int i = 1; i <= n; i++)
		if(task[i].F != task[i - 1].F){
			uni[++k].F = task[i].F;
			uni[k].S.PB(task[i].S);
		}
		else uni[k].S.PB(task[i].S);
	long long int m = 0, t = 0;
	 for(int i = 1; i <= k; i++){
	 	for(int j = 0; j < uni[i].S.size(); j++){
			t += (uni[i].F - m - 1) * get(n);
			a[uni[i].S[j]] = t + get(uni[i].S[j]);
			t += get(n);  
			m = uni[i].F;
		}
	 	for(int j = 0; j < uni[i].S.size(); j++) update(n, uni[i].S[j], -1);
	 }
	 for(int i = 1; i <= n; i++){
	 	OUT a[i]; newline;
	 }
	 return 0;
}