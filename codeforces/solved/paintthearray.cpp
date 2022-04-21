/*
Problem: find d if members of array a_2k % d == 0 and a_2k+1 % d != 0 (if members a0, a2, a4 were divisible by d but a1, a3, a5 weren't)
Algoritm: gcd of all numbers through the array yields their common divisibility; if m = gcd(a, b) then a%m == 0 and b%m == 0
Implementation: use an array instead of variables to store certain numbers if you are using even/odd since you can do t[i%2] when iterating through

1618C Div 3
*/

#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
#define arr array;

void solve(){
	ll n; cin >> n;
	ll a[n];
	for (ll &t:a) cin >> t;

	if (n==1){
		cout << a[0] << "\n";
		return;
	}

	ll gcd_a=a[0], gcd_b=a[1];
	for (int i=0; i<=1; i++){
		for (int j=i; j<n; j+=2){
			if (i==0) gcd_a = gcd(gcd_a, a[j]);
			else gcd_b = gcd(gcd_b, a[j]);
		}
	}

	vector<bool> t(2, true);
	for (int i=0; i<n; i++){
		if (i%2) t[1] = t[1] and (a[i]%gcd_a);
		else t[0] = t[0] and (a[i]%gcd_b);
	}

	ll ans = 0;
	if (t[0]) ans = max(ans, gcd_b);
	else if (t[1]) ans = max(ans, gcd_a);

    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}

	return 0;
}