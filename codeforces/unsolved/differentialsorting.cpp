#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    if (is_sorted(a.begin(), a.end())){
        cout << 0 << endl;
        return;
    }

    if (n == 2){
        cout << -1 << endl;
        return;
    }
    // case n==3
    //
    int s = abs(a[0] - a[1]);
    int cnt=0;

    for (int i=2; i<n; i++){
        if (a[i] == s) cnt++;
    }

    cout << n-cnt << endl;
    for (int i=0; i<n; i++){
        /* cout << max(a[0], a[1]) << " " << min(a[0], a[1]) */
    }


}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while (t--){
   		solve();
   	}
}
