#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    for (int i=1; i<n; i+=2){
        if (a[i]%2 != a[1]%2){
            cout << "NO" << endl;
            return;
        }
    }
    for (int i=0; i<n; i+=2){
        if (a[i]%2 != a[0]%2){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while (t--){
        solve();
    }
}

