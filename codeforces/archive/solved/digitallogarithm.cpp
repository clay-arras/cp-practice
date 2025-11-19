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
    vector<int> a, b;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    for (int i=0; i<n; i++){
        int t; cin >> t;
        b.push_back(t);
    }

    int ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> inter;
    set_intersection(a.begin(),a.end(), b.begin(), b.end(), back_inserter(inter));

    vector<int> tmp;
    set_difference(a.begin(), a.end(), inter.begin(), inter.end(), back_inserter(tmp));
    a = tmp;

    tmp = vector<int>();
    set_difference(b.begin(), b.end(), inter.begin(), inter.end(), back_inserter(tmp));
    b = tmp;

    for (int i=0; i<n-(int)inter.size(); i++){
        if (a[i] > 9){
            a[i] = floor(log10(a[i]) + 1);
            ans++;
        }
        if (b[i] > 9){
            b[i] = floor(log10(b[i]) + 1);
            ans++;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    inter = vector<int>();
    set_intersection(a.begin(),a.end(), b.begin(), b.end(), back_inserter(inter));

    tmp = vector<int>();
    set_difference(a.begin(), a.end(), inter.begin(), inter.end(), back_inserter(tmp));
    a = tmp;

    tmp = vector<int>();
    set_difference(b.begin(), b.end(), inter.begin(), inter.end(), back_inserter(tmp));
    b = tmp;

    for(int i=0; i<(int)a.size(); i++){
        if (a[i] != 1) ans++;
        if (b[i] != 1) ans++;
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
