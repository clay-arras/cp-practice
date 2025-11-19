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

int a, d, n, sum;
set<int> set_h;
vector<int> h;
int cost(int v){ return max(0, a-sum+h[v]) + max(0, d-h[v]); }

void solve(){
    cin >> n;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        set_h.insert(t);
        sum += t;
    }

    for (int i : set_h)
        h.push_back(i);

    debug(h);
    int m; cin >> m;
    while(m--){
        cin >> d >> a;

        for (int i=0; i<(int)h.size(); i++){
            cout << cost(i) << " ";
            /* cout << "(" << max(0, a-(sum-h[i])) << ", " << max(0, d-h[i]) << ") " << endl; */
        }
        cout << endl;
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
