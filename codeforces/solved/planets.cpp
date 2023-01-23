#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

int arr[101];
void solve(){
    int n, c; cin >> n >> c;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        arr[t]++;
    }
    long long ans = 0;
    for (int i=0; i<=100; i++){
        ans += min(c, arr[i]);
    }
    cout << ans << endl;

    fill(arr, arr+101, 0);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
