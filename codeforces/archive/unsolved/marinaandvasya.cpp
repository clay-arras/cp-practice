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
    int n, t; cin >> n >> t;
    string s1, s2; cin >> s1 >> s2;

    // greedy: do the same ones first, then do the different ones;
    // find same indices and take their char
    vector<char> ans(n, '\0');
    vector<int> s;

    for (int i=0; i<n; i++){
        if (s1[i] == s2[i]){
            s.push_back(i);
        }
    }

    int diff = n-(int)s.size();
    if (diff/2 + (int)s.size() < t){
        cout << -1 << endl;
        return;
    }


}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t = 1;
    while(t--){
        solve();
    }
}
