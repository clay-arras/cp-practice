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
    int n, m; cin >> n >> m;
    vector<int> a;

    for (int i=0; i<m; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    debug(a, n);
    vector<int> r;
    for (int i=0; i<m; i++){
        int d;
        if (i == m-1){
            d = n-a[i] + a[0]-1;
        }else{
            d = a[i+1] - a[i]-1;
        }
        r.push_back(d);
    }
    sort(r.rbegin(), r.rend());
    debug(r);

    int minus = 0;
    int ans = 0;
    for(int i=0; i<m; i++){
        ans += max(r[i]-minus-1, 0);
        if (r[i]-minus == 1) ans++;
        minus += 4;
    }
    cout << n-ans << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
