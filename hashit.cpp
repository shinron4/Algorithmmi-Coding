#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char s[101][20];

int hsh(char a[]){
	int h = 0, len = strlen(a);
	for(int i = 0; i < len; i++) h += a[i] * (i + 1);
	h *= 19;
	return h % 101;
}

int findfree(char a[], int hsh){
	int pos, pos2, f = 0;
	for(int i = 0; i < 20; i++){
		pos = (hsh + i * i + 23 * i) % 101;
		if(!strlen(s[pos]) && !f) pos2 = (f = 1, pos); 
		else if(strlen(s[pos]) && !strcmp(s[pos], a)) return -1;
 	}
	return f ? pos2 : -1;
}

int findele(char a[], int hsh){
	int pos;
	for(int i = 0; i < 20; i++){
		pos = (hsh + i * i + 23 * i) % 101;
		if(strlen(s[pos]) && !strcmp(s[pos], a)) return pos;
	}
	return -1;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n, pos, keys = 0;
		char a[20];
		cin >> n;
		for(int j = 0; j < n ; j++){
			cin >> a;
			switch(a[0]){
				case 'A' : 
					pos = strlen(a + 4) ? findfree(a + 4, hsh(a + 4)) : -1;
					if(pos != -1){
						strcpy(s[pos], a + 4);
						keys++;
					}
					break;
				case 'D' :
					pos = strlen(a + 4) ? findele(a + 4, hsh(a + 4)) : -1;
					if(pos != -1){
						s[pos][0] = '\0';
						keys--;
					}
					break;
			}
		}
		cout << keys << "\n";
		for(int j = 0; j < 101; j++)
			if(strlen(s[j])){
				cout << j << ":" << s[j] << "\n";
				s[j][0] = '\0';
			}
	}
	return 0;
}