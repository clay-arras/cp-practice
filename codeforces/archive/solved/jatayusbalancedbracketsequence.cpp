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

    int cnt=0;
    for (int i=0; i<2*n-1; i++){
        if (s[i] == '(' and s[i+1] == '(')
            cnt++;
    }
    cout << 1+cnt << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
