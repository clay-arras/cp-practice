#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    int r = k % n;
    int e = k / n;

    int ans=0;
    for (int i=30; i>30-e; i--){
        ans |= (1 << i);
    }
    // find the greatest bit that is k-n
    for (int i=30-e; i>=0; i--){
        int cnt=0;
        for (int j=0; j<n;j++){
            cnt += a[j] && (1 << i);
        }
        if (cnt > k-n){
            ans |= (1 << i);
            break;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--){
        solve();
    }
}

