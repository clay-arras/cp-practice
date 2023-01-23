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
    int n, cm, cq; cin >> n >> cm >> cq;
    long long sum = 0;

    vector<int> a;
    a.push_back(0);
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
        sum += t;
    }
    n++;

    long long cost = 1LL*sum * cq;
    long long ans = cost;
    for (int i=1; i<n; i++){
        long long dist = a[i] - a[i-1];
        long long val = 1LL*cm*dist - 1LL*cq*(n-i-1LL)*dist;
        cost += val;
        ans = min(ans, cost);
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
