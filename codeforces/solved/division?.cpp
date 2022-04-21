#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    cout << "Division ";

    if (n >= 1900) cout << 1 << endl;
    else if (n >= 1600) cout << 2 << endl;
    else if (n >= 1400) cout << 3 << endl;
    else cout << 4 << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

