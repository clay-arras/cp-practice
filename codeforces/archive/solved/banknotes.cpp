#include <bits/stdc++.h>
using namespace std;

long long tens[10];
void solve(){
    long long n, k; cin >> n >> k;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    k++;

    vector<long long> b(n-1);
    for (int i=0; i<n-1; i++){ b[i] = tens[a[i+1]] - tens[a[i]]; }

    unsigned long long ans=0; int i;
    for (i=0; i<n-1; i++){
        long long t = min(b[i], k*tens[a[i]]);
        ans += t; k -= t/tens[a[i]];
    }

    ans += ((unsigned long long)tens[a[i]])*k;
    cout << ans << endl;
}

int main() {
    /* freopen("input.txt", "r", stdin); */
    for (int i=0; i<10; i++){ tens[i] = pow(10, i); }

    int t; cin >> t;
    while(t--){
        solve();
    }
}
