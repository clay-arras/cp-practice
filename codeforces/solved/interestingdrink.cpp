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
    /* int x[n]; for (int& t : x) cin >> t; */

    /* sort(x, x+n); */
    vector<int> x;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        x.push_back(t);
    }
    sort(x.begin(), x.end());

    int q; cin >> q;
    while(q--){
        int m; cin >> m;

        auto b = upper_bound(x.begin(), x.end(), m);
        cout << b - x.begin() << endl;
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t=1;
   	while(t--){
   		solve();
   	}
}
