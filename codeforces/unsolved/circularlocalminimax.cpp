#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    int n; cin >> n;

    vector<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    if (n % 2 == 1){
        cout << "NO\n";
        return;
    }

    sort(a.begin(), a.end());
    if (a[n/2] == a[n/2-1]){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i=0; i<n/2; i++){
        cout << a[i] << " ";
        cout << a[i+n/2] << " ";
    }
    cout << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
// b s b s b
// claim: if the middle two are distinct, then it is possible
// claim is wrong lmao
//
