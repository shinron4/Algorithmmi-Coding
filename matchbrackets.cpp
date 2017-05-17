#include <iostream>
#include <stack>

#define MP make_pair
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "

using namespace std; 

stack < pair<int, int > > s;

int main(){
	int n, x, d = -1, c = 0;
	pair <int, int> md, mc;
	md.F = mc.F = -1;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x == 1){
			s.push(MP(0, c));
			s.push(MP(1, i));
			d++;
			if(d > md.F){
				md.F = d;
				md.S = i;
			}
			c = 0;
		}
		else{
			d--;
			if(s.top().F == 1){
				c += 2;
				s.pop();
				if(c > mc.F){
					mc.F = c;
					mc.S = s.top().S;
				}
			}
			while(!s.empty() && s.top().F != 1){
				c += s.top().S;
				s.pop();
			}
		}
	}
	cout << md.F + 1; space; cout << md.S + 1; space; cout << mc.F; space; cout << mc.S + 1; newline;
	return 0;
}