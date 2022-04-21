// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
bool cows[10][10];

void flip(int i, int j){
	for (int p=0; p<=i; p++){
		for (int q=0; q<=j; q++)
		{
			cows[p][q] = !cows[p][q];
		}
	}
}

int main() {
	freopen("cowtip.in", "r", stdin);
  	freopen("cowtip.out", "w", stdout);

	int n; cin >> n;

	string row;
	for (int i=0; i<n; i++){
		cin >> row;
		for (int j=0; j<n; j++){
			cows[i][j] = (row[j] == '1' ? true : false);
		}
	}
	
	int ans = 0;
	int x=n-1, y=n-1;
	while(x>=0 && y>=0){
		if (cows[x][y]){
			flip(x, y); 
			ans++;
		}

		if (x != y) {
			if (cows[y][x]){
				flip(y, x);
				ans++;
			}
		}
		if (x != 0) {
			x--;
		}
		else {
			y--; 
			x=y;
		}
	}
	cout << ans << endl;
}



