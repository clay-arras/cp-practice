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
    string s; cin >> s;

    bool last = false;
    int t = 0;
    if (s[n-1] == '1'){
        last = true;
    }

    s+='0', n++;
    for (int i=1; i<n; i++){
        if (s[i-1] == '1' and s[i] == '0') t++;
    }

    int ans = 2*t - 1;
    if (last) ans--;
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
