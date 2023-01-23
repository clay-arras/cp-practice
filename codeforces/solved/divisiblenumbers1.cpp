#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    long long a_1, b_1, a_2, b_2; cin >> a_1 >> b_1 >> a_2 >> b_2;
    long long t = a_1*b_1;

    if (t == 1){
        cout << a_2 << " " << b_2 << endl;
        return;
    }

    for (long long i=a_1+1; i<=a_2; i++){
        long long j = t/gcd(i, t);

        j *= floor(b_2*1.0/j);

        if (j > b_1 and j <= b_2 and (j*i) % t == 0){
            cout << i << " " << j << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
