#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    long long s=1;
    for (int i=1; i<n; i++){
        s += a[i];
        s ++;
    }
    s += a[n-1];

    cout << ((s <= m) ? "YES" : "NO") << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

