#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

int pow2(int n) {
    return (n & (~(n - 1)));
}

void solve(){
    int n; cin >> n;
    vector<int> p, a;

    int sum=0;
    int test=0;
    for (int i=1; i<=n; i++){
        int t; cin >> t;

        sum += log2(max(1, pow2(t)));
        test += log2(max(1, pow2(i)));
        p.push_back(log2(max(1, pow2(i))));
    }

    if (sum + test < n){
        cout << -1 << endl;
        return;
    }

    sort(p.rbegin(), p.rend());

    int i=0;
    while (sum < n){
        sum += p[i];
        i++;
    }
    cout << i << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
