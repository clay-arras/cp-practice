using namespace std;
#include <bits/stdc++.h>

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    long long n, q; cin >> n >> q;

    long long sum = 0;
    vector<long long> c, t;
    for (int i=0; i<n; i++){
        long long x; cin >> x;
        c.push_back(x);
        t.push_back(0);
        sum += x;
    }

    long long wt = -1, wv = -1;
    for(int tt = 1; tt <= q; tt++){
        int o; cin >> o;
        if (o == 1){
            long long i, x; cin >> i >> x;
            i--;

            if (wt > t[i]){
                sum += x - wv;
            }else{
                sum += x - c[i];
            }
            c[i] = x;
            t[i] = tt;
        }else{
            long long x; cin >> x;
            sum = x*n;
            wt = tt;
            wv = x;
        }
        cout << sum << "\n";
    }
}
