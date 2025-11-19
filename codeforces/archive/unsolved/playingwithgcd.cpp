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

    vector<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    if (n == 1){
        cout << "YES" << endl;
        return;
    }

    vector<int> b;
    b.push_back(a[0]);
    for (int i=1; i<n; i++){
        b.push_back(a[i]*a[i-1]);
    }
    b.push_back(a[n-1]);

    bool ok = true;
    for (int i=0; i<n; i++){
        if (a[i] != gcd(b[i], b[i+1]))
            ok = false;
    }

    debug(a);
    debug(b);
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
