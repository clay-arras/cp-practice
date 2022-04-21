#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int b[n];
    for (int &t : b) cin >> t;

    map<int, int> a;
    for (int i=0; i<n; i++){
        int t = b[i];
        a[t]++;
        if (a[t] >= 3){
            cout << t << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

