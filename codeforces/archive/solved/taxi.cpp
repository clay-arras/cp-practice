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

    vector<int> a(5, 0);
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a[t]++;
    }

    if (a[1] > a[3])
        a[2] += ceil((a[1]-a[3])*1.0/2);

    cout << a[4] + a[3] + ceil(a[2]*1.0/2) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

