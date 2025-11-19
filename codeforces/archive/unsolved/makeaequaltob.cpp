#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a, b;

    int a_cnt=0, b_cnt=0;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
        a_cnt += t;
    }
    for (int i=0; i<n; i++){
        int t; cin >> t;
        b.push_back(t);
        b_cnt += t;
    }

    int ans = 0;
    for (int i=0; i<n; i++){
        ans += a[i] ^ b[i];
    }

    ans = min(ans, abs(a_cnt - b_cnt) + 1);
    /* debug(a); */
    /* debug(b); */
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
