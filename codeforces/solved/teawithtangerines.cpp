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
        cout << 0 << endl;
        return;
    }

    int ans=0;
    for (int i=1; i<n; i++){
        double plus = 1;

        for (double b = 1e8; b >= 1e-12; b /= 2) {
            while (ceil(a[i]*1.0/(plus+b)) >= 2.0*a[0]) plus += b;
        }
        ans += ceil(plus)-1;
    }
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
