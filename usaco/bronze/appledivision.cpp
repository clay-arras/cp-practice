// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> apple;
int n;

ll solve(int i, ll s1, ll s2){
	if(i == n){
		return abs(s1 - s2);
	}
	return min(solve(i + 1, s1 + apple[i], s2), solve(i + 1, s1, s2 + apple[i]));
}

int main() {
	 cin >> n;

	int a;
	for (int i=0; i<n; i++){
		cin >> a;
		apple.push_back(a);
	}
	cout << solve(0, 0, 0);
}
