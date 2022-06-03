#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
/* #define cerr if(0) cerr */
#include <debug.h>
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> c;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        c.push_back(t);
    }

    int k = 2;
    for (int i=1; i<n; i++){
        if (c[i] - c[i-1] != 1){
            if (k > 0 and k - (c[i] - c[i-1] - 1) >= 0)
                k -= c[i] - c[i-1] - 1;
            else{
                cout << "NO" << endl;
                return;
            }
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

