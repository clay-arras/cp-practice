#include <bits/stdc++.h>
using namespace std;

long long sum;
long long odds;
long long check(long long d){
    long long ones = ceil(d*1.0/2);
    long long twos = floor(d*1.0/2);
    long long s = sum;

    ones -= odds;
    s -= odds;
    if (ones < 0) return false;
    else { return 2*twos + ones >= s; }
}

long long bs(long long lo, long long hi, function<bool(long long)> f) {
	hi++;
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;
		if (f(mid)) { hi = mid;
		}else{ lo = mid + 1; }
	}
	return lo;
}

void solve(){
    int n; cin >> n;
    int a[n], mx=0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sum=0, odds=0;
    for (int i : a){
        sum += (mx - i);
        odds += (mx - i)%2;
    }

    cout << bs(0, 1e15, check) << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while(t--){
        solve();
    }
}
