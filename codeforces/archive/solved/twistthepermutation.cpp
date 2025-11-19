#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& t : a) cin >> t;

    int ans[n];
    for (int i=n; i>=1; i--){
        int in = -1;
        for (int j=0; j<i; j++){
            if (a[j] == i){
                in = j+1;
                break;
            }
        }
        int inc = ((in-i)%i + i)%i;
        rotate(a.begin(), a.begin()+inc, a.begin()+i);
        ans[i-1] = inc;
    }
    for (int t : ans) cout << t << " ";
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
