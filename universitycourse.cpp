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

int main(){
	int t, pre[100000], valid;
	IN t;
	for(int i = 0; i < t; i++){
		int n;
		IN n;
		for(int j = 0; j < n; j++)
			IN pre[j];
		valid = 0;
		for(int j = 0; j < n; j++)
			if(pre[j] - 1 >= valid)
				valid = pre[j];
		OUT n - valid; newline;
	}
	return 0;
}