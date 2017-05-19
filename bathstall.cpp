#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class Compare
{
public:
    bool operator() (pair<long long int, long long int> a, pair<long long int, long long int> b){
    	bool temp;
       	if((a.second - a.first - 2)/2 < (b.second - b.first - 2)/2)
       		temp = true;
       	else if((a.second - a.first - 2)/2 == (b.second - b.first - 2)/2){
       		if(ceil((a.second - a.first - 2)/2.0) < ceil((b.second - b.first - 2)/2.0))
       			temp = true;
       		else
       			temp = false;
       	}
       	else
       		temp = false;
       return temp;
    }
};

priority_queue< pair<long long int, long long int>, vector < pair<long long int, long long int> >, Compare > Q;
long long int N, K, x, y, k;
pair<long long int, long long int>temp2, temp3;

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N >> K;
		temp2.first = 0;
		temp2.second = N + 1;
		if(temp2.first < temp2.second - 1) Q.push(temp2);
		k = 0;
		while(k < K && !Q.empty()){
			x = Q.top().first;
			y = Q.top().second;
			if(k == K - 1){
				cout << "Case #" << i + 1 << ": " << ceil((y - x - 2)/2.0) << " " << (y - x - 2)/2 << "\n";
			}
			Q.pop();
			temp2.first = x;
			temp3.first = temp2.second = x + (y - x - 2)/2 + 1; 
			temp3.second = y;
			if(temp2.first < temp2.second - 1) Q.push(temp2);
			if(temp3.first < temp3.second - 1) Q.push(temp3);
			k++;
		}
		while(!Q.empty()) Q.pop();
	}
	return 0;
} 