// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n, l; cin >> n >> l;
	string a[n];

	int input;
	for (string &t : a){
		cin >> input;
		t = bitset<64>(input).to_string();
		t = t.substr(t.length() - l);
	} 

	string ans = ""; int sum;
	for (int i=0; i<l; i++){
		sum = 0;

		for (string j: a) sum += j[i] - '0';

		if (2*sum < n) ans += "0";
		else ans += "1";
	}
	cout << stoi(ans, nullptr, 2) << endl;
}

int main() {
	int N; cin >> N;
	while (N--){
		solve();
	}
}
