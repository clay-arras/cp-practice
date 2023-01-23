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
    int N; cin >> N;
    N--;
    vector<int> p(N+1, 0);

    int n=N;
    while(n){
        int t = ceil(sqrt(n));
        t = t*t;

        for (int i=n; i>=floor(t*1.0/2); i--){
            p[i] = t-i;
            p[t-i] = i;
        }
        n = min(t-n-1, n-1);
        n = max(n, 0);
    }

    for (int i : p)
        cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
