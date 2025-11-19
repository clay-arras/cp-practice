// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
void solve(){
	int a, b, c; cin >> a >> b >> c;

	if ((2*b-c)%a == 0){
		cout << "yES" << endl;
		return;
	}
	else if (((a+c)/2)%b == 0 && (a+c)%2 == 0){
		cout << "YeS" << endl;
		return;
	}
	else if ((2*b-a)%c == 0){
		cout << "YEs" << endl;
		return;
	}
	cout << "NO" << endl;
}

int main() {
	int N; cin >> N;
	while (N--){
		solve();
	}
}

