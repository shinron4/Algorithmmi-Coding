#include <iostream>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 

using namespace std;

long int sum[1 << 20], score[1 << 20], a[20], MAX;

int main(){
	int n ;
	cin >> n;
	for(int i = 0; i < n; i++){
		IN a[i];
	}
	MAX = (1 << n) - 1;
	for(int i = 0; i < n; i++){
		long int mask = (1 << i);
		for(long int j = 0; j < (1 << n); j++)
			if((j & mask) != 0){
				sum[j] += a[i];
			}
	}
	score[0] = 0;
	for(long int i = 1; i < 1 << n; i++){
		long int max = -1, rs = sum[(~i & MAX)];
		for(int j = 0; j < n; j++){
			long int mask = 1 << j;
			if((i & mask) != 0)
				if(score[i ^ mask] + rs % a[j] > max)
					max = score[i ^ mask] + rs % a[j];
		}
		score[i] = max;
	}
	OUT score[(1 << n) - 1]; newline;
	return 0;
}