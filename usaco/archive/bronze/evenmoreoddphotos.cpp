// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int odd=0, even=0;

	int i;
	while (n--){
		cin >> i; 
		i%2 ? odd++ : even++;
	}
	
	while(odd > even){
		odd -= 2;
		even++;
	}
	if (even > odd+1) even = odd+1;
	cout << even+odd << endl;
}
