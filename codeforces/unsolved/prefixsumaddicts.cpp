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
    int n, k; cin >> n >> k;

    vector<int> a;
    while((int)a.size() <= n-k)
        a.push_back(0);

    for (int i=0; i<k; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    reverse(a.begin(), a.end());
    vector<int> x;

    for (int i=0; i<k; i++){
        x.push_back(a[i] - a[i+1]);
    }

    reverse(x.begin(), x.end());
    debug(a);
    debug(x);
    cout << (n-k) << endl;
    if (is_sorted(x.begin(), x.end()) and (n-k)*x[1] >= x[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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
