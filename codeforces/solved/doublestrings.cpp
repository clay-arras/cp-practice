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

    map<string, int> m;
    vector<string> a;
    for (int i=0; i<n; i++){
        string t; cin >> t;
        a.push_back(t);
        m[t] = 1;
    }

    bool found;
    for (int i=0; i<n; i++){
        found = false;
        string s; s = a[i];
        for (int j=1, len=(int)s.size(); j<len; j++){
            string l = s.substr(0, j);
            string r = s.substr(j);
            if (m[l] and m[r]){
                cout << 1;
                found = true;
                break;
            }
        }
        if (!found) cout << 0;
    }
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
