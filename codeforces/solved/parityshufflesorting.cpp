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
    if (n == 1){
        cout << 0 << endl;
        return;
    }

    vector<pair<int, int> > ans;
    ans.push_back(make_pair(1, n));
    for (int i=1; i<n-1; i++){
        if ((a[0] + a[i]) % 2 == 1){
            ans.push_back(make_pair(1, i+1));
        }else{
            ans.push_back(make_pair(i+1, n));
        }
    }

    cout << (int)ans.size() << endl;
    for (auto i : ans){
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
