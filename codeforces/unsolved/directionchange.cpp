#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;

    int a = min(n, m);
    int b = max(n, m);

    if (a == 1 and b > 2){
        cout << -1 << endl;;
        return;
    }
    int t = 2*(a-1);
    int t0 = (b - 1 - (a-1));
    t0 = floor(t0/2) * 2;
    int t1 = b-a;

    cout << t + t0 + t1 << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

