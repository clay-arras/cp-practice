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
    int n; cin >> n;
    vector<int> x, y;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        x.push_back(t);
    }
    for (int i=0; i<n; i++){
        int t; cin >> t;
        y.push_back(t);
    }

    int zeroes = 0;
    vector<int> d_pos, d_neg;
    for (int i=0; i<n; i++){
        int diff = x[i] - y[i];
        if (diff < 0){
            d_neg.push_back(diff);
        }else if (diff > 0){
            d_pos.push_back(diff);
        }else{
            zeroes++;
        }
    }
    sort(d_neg.rbegin(), d_neg.rend());
    sort(d_pos.begin(), d_pos.end());

    int ans = 0, j = 0;
    for (int i=0; i<(int)d_pos.size(); i++){
        while(j<(int)d_neg.size() and d_pos[i] + d_neg[j] > 0){
            j++;
        }

        if (j<(int)d_neg.size()){
            if (d_pos[i] + d_neg[j++] <= 0)
                ans++;
        }
    }

    int neg = (int)d_neg.size() - ans;
    ans += max(0, ((neg+zeroes)/2));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
