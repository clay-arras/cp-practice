// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int K; 
int solve(int x){
	int n; double a;
	a = (x*x + x + 2*K)/2;
	n = ceil(sqrt(a));
	
	return 2*n - x - 1;
}

int main() {
	// freopen("race.in", "r", stdin);
	// freopen("race.out", "w", stdout);

	int N; cin >> K >> N;

	int x; 
	while(N--){
		cin >> x;
		cout << solve(x) << endl;
	}
}
