#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k, x; cin >> n >> k >> x;
    vector<long long> a;

    for (int i=0; i<n; i++){
        long long t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    int g=1;
    multiset<long long> b;
    for (int i=1; i<n; i++){
        if (a[i] - a[i-1] <= x){ continue; }
        b.insert(ceil((a[i] - a[i-1])*1.0/x)-1);
    }

    g += (long long)b.size();

    for (auto it = b.begin(); it != b.end() and k >= 0; ++it){
        if (k - *it >= 0){
            g--;
            k -= *it;
        }
    }
    cout << g << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	/* freopen("input.txt", "r", stdin); */

    int t=1;
    while (t--){
        solve();
    }
}
