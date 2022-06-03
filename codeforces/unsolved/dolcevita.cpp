#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    int n, x; cin >> n >> x;

    vector<int> c;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        c.push_back(t);
    }
    sort(c.begin(), c.end());

    vector<long long> p;
    p.push_back(c[0]);
    for (int i=1; i<n; i++){
        long long l = *(--p.end());
        if (l > x) break;
        p.push_back(l + c[i]);
    }
    reverse(p.begin(), p.end());

    long long d = 0; long long ans = 0;
    int len = (int)p.size();
    for (auto it = p.begin(); it != p.end(); ++it){
        int cand = (len - (it - p.begin()));
        int cost = *it + cand*d;
        int days = (x - cost)*1.0/cand + 1;

        d += days;
        ans += days * cand;
    }
    cout << max(0LL, ans) << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--){
        solve();
    }
}

