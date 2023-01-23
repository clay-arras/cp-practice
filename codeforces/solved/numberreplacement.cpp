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
    string s; cin >> s;
    map<int, char> m;

    for (int i=0; i<n; i++){
        /* cout << m.count(a[i]) << " "; */
        /* debug(s[i], a[i]); */
        if (m.count(a[i]) == 0){
            m[a[i]] = s[i];
        }
        if (m[a[i]] != s[i]){
            cout << "NO" << endl;
            return;
        }
    }
    /* debug(m); */
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
