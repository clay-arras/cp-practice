// bug was that I was adding the ones after you can't anymore so there were negative values
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
    int n, x; cin >> n >> x;

    vector<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    vector<int> day;
    long long sum = 0;
    for (int i=0; i<n; i++){
        sum += a[i];
        if (sum <= x){
            int d = (x - sum)/(i+1) + 1;
            day.push_back(d);
        }
    }

    day.push_back(0);
    long long ans = 0;
    for (int i=0; i<(int)day.size()-1; i++){
        ans += (i+1) * (day[i] - day[i+1]);
    }
    cout << max(0LL, ans) << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--){
        solve();
    }
}

