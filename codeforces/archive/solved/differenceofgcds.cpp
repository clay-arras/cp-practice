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
    int n, l, r; cin >> n >> l >> r;

    vector<int> ans;
    for (int i=1; i<=n; i++){
        int lbound = floor(r/i)*i;
        int rbound = ceil(l/i)*i;

        if (lbound <= r and lbound >= l){
            ans.push_back(lbound);
        }else if (rbound <= r and rbound >= l){
            ans.push_back(rbound);
        }else{
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;

    for (int i : ans)
        cout << setprecision(10) << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
