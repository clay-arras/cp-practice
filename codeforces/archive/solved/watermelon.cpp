#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
	#ifndef ONLINE_JUDGE
   		freopen("input.txt", "r", stdin);
   		freopen("output.txt", "w", stdout);
   	#endif
	int N; cin >> N;

	if (N == 2) cout << "NO";
	else cout << (N%2 ? "NO" : "YES");

}