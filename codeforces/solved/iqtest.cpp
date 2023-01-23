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
    int n; cin >> n;

    vector<int> a[2];
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a[t%2].push_back(i+1);
    }

    if ((int)a[0].size() == 1)
        cout << a[0][0] << endl;
    else
        cout << a[1][0] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
