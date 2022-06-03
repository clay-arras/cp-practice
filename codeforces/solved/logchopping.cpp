#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include <debug.h>
#else
#define debug(...)
#endif

void solve() {
    int n; cin >> n;
    int ans=0;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        ans += --t;
        ans %= 2;
    }
    ans %= 2;
    debug(ans)

    cout << (ans ? "errorgorn\n" : "maomao90\n");
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--){
        solve();
    }
}
