// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int n; string mail;
bool dupes(int k){
	set<string> s;

	for (int i=0; i<=n-k; i++){
		if (s.count(mail.substr(i, k)) > 0) return true;
		s.insert(mail.substr(i, k));
	}
	return false;
}

int main() {
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	cin >> n >> mail;
	int k=1;
	while (dupes(k)) k++;

	cout << k << endl;
}
