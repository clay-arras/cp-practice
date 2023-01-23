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

    int g = -1;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);

        if (!i)
            g = t;
        g = gcd(t, g);
    }

    int altCost = 1e9;
    int cost = 0;
    for (int i=n-1; i>=0; i--){
        int t = gcd(a[i], i+1);
        if (g > gcd(t, g)){
            g = gcd(t, g);
            cost += n-i;
        }
        if (t == 1){
            altCost = min(n-i, altCost);
        }
    }
    cout << min(altCost, cost) << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
