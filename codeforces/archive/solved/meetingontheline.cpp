#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

int n;
vector<int> x, t;
const double MX = 1e8+9;
const double MN = 5e-7;

double cost(double m){
    double sum = 0;
    for (int i=0; i<n; i++){
        sum = max(abs(m - 1.0*x[i]) + t[i], sum);
    }
    return sum;
}

void solve(){
    cin >> n;

    cout << setprecision(10);
    for (int i=0; i<n; i++){
        int v; cin >> v;
        x.push_back(v);
    }
    for (int i=0; i<n; i++){
        int v; cin >> v;
        t.push_back(v);
    }

    long double ans = 0;
    for (long double b = MX; b > MN; b /= 2) {
        while (cost(ans+b) > cost(ans+b+MN)) ans += b;
    }
    cout << ans << endl;

    x.clear();
    t.clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}
