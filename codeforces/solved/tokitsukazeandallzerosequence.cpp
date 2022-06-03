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
    multiset<int> a;

    bool eq = false;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        if (a.count(t)) eq = true;
        a.insert(t);
    }

    if (a.count(0)){ cout << n-a.count(0) << endl; }
    else if (eq){ cout << n << endl; }
    else cout << n+1 << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
