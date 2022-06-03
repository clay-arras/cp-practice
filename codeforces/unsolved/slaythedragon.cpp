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

vector<long long> a;
long long n, x, y, s = 0;
long long cost (long long m){
    return max(0LL, x-a[m]) + max(0LL, y-(s-a[m]));
}
// overcounting

void solve(){
    cin >> n;

    set<long long> st;
    for (int i=0; i<n; i++){
        long long t; cin >> t;
        if (st.count(t) == 0){
            st.insert(t);
            a.push_back(t);
        }
        s += t;
    }
    sort(a.begin(), a.end());
    n = (long long)st.size();
    /* debug(n, a, a[n]); */

    int m; cin >> m;
    while (m--){
        cin >> x >> y;

        long long ans, p = 0;
        for (long long b = n; b >= 0.5; b /= 2)
            while (cost(p+b-1) > cost(p+b)) p += b;

        ans = cost(p);
        cout << ans << endl;
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
