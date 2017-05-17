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

long int c[200005], num;

vector< pair<char, long int> > query(200005);

vector< pair<long int, long int> > a, dista; 

long int get(int i){
	long int sum = 0;
	while(i > 0){
		sum += c[i];
		i -= i & -i;
	}
	return sum;
}

void update(int n, int i, int val){
	while(i <= n){
		c[i] += val;
		i += i & -i;
	}
}

int BITsearch(int i, int j, float k){
	int mid;
	while(i < j){
		mid = (i + j)/2;
		if(k <= get(mid))
			j = mid;
		else
			i = mid + 1;
	}
	return i;
}

int search(const vector< pair<long int, long int> > &a, int i, int j, float k){
	int mid;
	while(i < j){
		mid = (i + j)/2;
		if(k <= a[mid].F) j = mid;
		else i = mid + 1;
	}
	return i;
}

int main(){
	int q, idx;
	IN q;
	for(int i = 0; i < q; i++){
		IN query[i].F; IN query[i].S;
	}
	for(int i = 0; i < q; i++) if(query[i].F == 'I') a.PB(MP(query[i].S,0));
	sort(a.begin(), a.end());
	dista.PB(MP(a[0].F, 0));
	for(int i = 1; i < a.size(); i++) if(a[i].F != a[i - 1].F) dista.PB(MP(a[i].F, 0));
	for(int i = 0; i < q; i++){
		switch(query[i].F){
			case 'I' : 
				idx = search(dista, 0, dista.size() - 1, query[i].S);
				if(dista[idx].S == 0){
					update(dista.size(), idx + 1, 1);
					num++;
					dista[idx].S++;
				}				
				break;
			case 'D' :
				idx = search(dista, 0, dista.size() - 1, query[i].S);
				if((dista[idx].F == query[i].S) && dista[idx].S > 0){
					update(dista.size(), idx + 1, -1);
					num--;
					dista[idx].S = 0;
				}
				break;
			case 'K' :
				if(query[i].S > num) OUT "invalid";
				else{
					idx = BITsearch(1, dista.size(), query[i].S - 0.5);
					OUT dista[idx - 1].F;
				}
				newline;
				break;
			case 'C' :
				if(query[i].S > dista[dista.size() - 1].F) OUT num;
				else{
					idx = search(dista, 0, dista.size() - 1, query[i].S);
					OUT get(idx);
				}
				newline;
				break;
		}
	}
	return 0;
}