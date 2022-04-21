#include <bits/stdc++.h>
using namespace std; 

long long x, k;
long long lines;

bool check(long long m){
    auto f = [](long long v){return v * (v+1) / 2;};
    
    if (m <= k) return f(m) < x;
    else return f(k) + f(k-1) - f(lines-m) < x;
}

long long bs(long long lo, long long hi, function<bool(long long)> f) {
	lo--;
	while (lo < hi) {
		long long mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return min(lo+1, lines);
}

void solve(){
    cin >> k >> x;
    lines = 2*k-1;
    
    cout << bs(0, lines, check) << endl; 
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
