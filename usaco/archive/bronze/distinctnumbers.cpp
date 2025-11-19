// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	unordered_set<int> num;

	int a;
	for (int i=0; i<n; i++){
		cin >> a;
		num.insert(a);
	}
	cout << num.size();
}
