#include <iostream>
#include <cmath> 
#include <vector>
#include <cstring>
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
#define CHILD_SIZE 26

using namespace std;

vector<string> a(250000);

int search(int i, int j, string s){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(a[mid].compare(s) >= 0) j = mid;
		else i = mid + 1;
	}
	return a[i].compare(s) ? -1 : i;
}

struct tnode{
	struct tnode *c[CHILD_SIZE];
	int u, v, id;
	tnode(){
		for(int i = 0; i < CHILD_SIZE; i++) c[i] = 0;
		u = -1;
	}
};

void insert(struct tnode *n, string w, int l, int k){
	struct tnode *t= n;
	for(int i = l - 1; i >= 0; i--){
		if(!t->c[w[i] - 'a']) t->c[w[i] - 'a'] = new tnode();
		t->v = t->u;
		t->u = k;
		t = t->c[w[i] - 'a'];
	}
	t->v = t->u;
	t->u = k;
}

int rhyme(struct tnode *n, string w, int k){
	struct tnode *t = n;
	int min = -1;
	for(int i = w.length() - 1; i >= 0; i--){
		min = t->u == k ? (t->v >= 0 ? t->v : min) : t->u;
		if(!t->c[w[i] - 'a']) break;
		t = t->c[w[i] - 'a'];
	}
	min = t->u == k ? (t->v >= 0 ? t->v : min) : t->u;
	return min;
}

int main(){
	int i = 0, k;
	string s;
	struct tnode *t = new tnode();
	for(; getline(cin, a[i]) && a[i].length(); i++);
	sort(a.begin(), a.begin() + i);
	for(int j = i - 1; j >= 0; j--) insert(t, a[j], a[j].length(), j);
	 while(getline(cin, s) && s.length()){
	 	k = rhyme(t, s, search(0, i - 1, s));
	 	OUT (k >= 0 ? a[k] : "NULL"); newline;
	  }
	return 0;
}