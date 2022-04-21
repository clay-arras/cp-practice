#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    int a[n]; for (int& t : a) cin >> t;
    int b[n]; for (int& t : b) cin >> t;

    vector<int> av, bv;
    for (int i=0; i<n; i++){
        av.push_back(max(a[i], b[i]));
        bv.push_back(min(a[i], b[i]));
    }
    long long ans=0;
    for (int i=0; i<n-1; i++){
        ans += abs(av[i] - av[i+1]) + abs(bv[i] - bv[i+1]);
    }
    cout << ans << endl;
}

int main() {
    /* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while(t--){
        solve();
    }
}
