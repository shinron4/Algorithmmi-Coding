#include <iostream>

using namespace std;

//Bertrand's Ballot Theorem
int main(){
	int T;
	float N, M;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N >> M;
		cout << "Case #" << i + 1 << ": " << (N - M)/(N + M) << "\n"; 
	}
	return 0;
}