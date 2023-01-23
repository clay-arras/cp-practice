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
    int q; cin >> q;

    unordered_map<long long, int> s;
    s[0] = 1;

    while(q--){
        char c; cin >> c;
        long long t; cin >> t;

        if (c == '+'){
            s[t] = 1;

        }else if (c == '?'){
            long long tt = t;
            while(s[tt] == 1){
                tt += t;
            }
            cout << tt << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
