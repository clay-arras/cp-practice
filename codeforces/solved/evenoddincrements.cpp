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
    int n, q; cin >> n >> q;
    long long e=0, o=0, en=0, on=0;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        (t%2 ? (o+=t, on++) : (e+=t, en++));
    }

    while(q--){
        int p, v; cin >> p >> v;
        if (p%2){
            o+=on*v;
            if (v%2){
                en += on;
                e += o;
                on=0, o=0;
            }
        }else{
            e+=en*v;
            if (v%2){
                on += en;
                o += e;
                en=0, e=0;
            }
        }
        cout << o + e << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
