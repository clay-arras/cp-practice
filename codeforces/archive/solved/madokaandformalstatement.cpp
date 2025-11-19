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
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    for (int i=0; i<n; i++){
        int t; cin >> t;
        b.push_back(t);
    }

    int ok = true;
    for (int i=0; i<n; i++){
        if (a[i] > b[i]){
            ok = false;
        }
    }
    for (int i=0; i<n-1; i++){
        if (a[i] < b[i] and b[i] > b[i+1] + 1){
            ok = false;
        }
    }
    if (a[n-1] < b[n-1] and b[n-1] > b[0] + 1){
        ok = false;
    }
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
