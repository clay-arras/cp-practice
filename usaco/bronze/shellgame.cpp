// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("shell.in", "r", stdin);
  	freopen("shell.out", "w", stdout);

	int swaps; cin >> swaps;
	int points[3], loc[3];

	for (int j=0; j<3; ++j){ 
		loc[j] = j;
		points[j] = 0;
	}

	for (int i=0; i<swaps; ++i){
		int a, b, g;
		cin >> a >> b >> g;		
		--a, --b, --g;

		swap(loc[a], loc[b]);
		points[loc[g]]++;
	}
	cout << max({points[0], points[1], points[2]});

}




