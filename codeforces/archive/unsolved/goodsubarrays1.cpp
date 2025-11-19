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

    int ans = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (a[j] >= j-i+1){
                ans++;
            }else{
                break;
            }
        }
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
