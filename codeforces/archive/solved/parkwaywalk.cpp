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
    int n, m; cin >> n >> m;
    /* vector<int> a; */

    int sum = 0;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        /* a.push_back(t); */
        sum += t;
    }
    cout << max(0, sum - m) << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
