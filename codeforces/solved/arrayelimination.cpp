#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    int div = -1;
    for (int i=0; i<=30; i++){
        int cnt=0;
        for (int j=0; j<n; j++){
            if ((1 << i) & a[j]) cnt++;
        }
        if (div == -1 and cnt){
            div = cnt;
            continue;
        }

        if (cnt){ div = gcd(div, cnt); }
    }

    if (div == -1){
        for (int i=1; i<=n; i++){ cout << i << " "; }
        cout << endl;
        return;
    }

    for (int i=1; i<=div; i++){
        if (div%i == 0) cout << i << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

