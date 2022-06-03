#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    int l = 0;
    while (a[l] and l < n-1) l++;
    int r = n-1;
    while (a[r] and r > 0) r--;

    /* debug(a); */
    cout << (r - l < 0 ? 0 : r - l + 2) << endl;
    /* debug(l, r); */
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
