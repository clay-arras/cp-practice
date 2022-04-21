// how did i take so many attempts to get it right

#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
#define arr array;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int n, m, a; cin >> n >> m >> a;
   	cout << (ll) (ceil(n*1.0/a) * ceil(m*1.0/a));

	return 0;
}