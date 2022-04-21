#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    multiset<long long> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.insert(t);
    }
    while (a.size() != 1){
        auto u = a.begin();
        auto v = ++a.begin();

        if (*v - *u > 1){
            for (int i : a) cout << i << " ";
            cout << endl;
            cout << "NO\n";
            return;
        }else{
            long long t = *u + *v;
            a.erase(u);
            a.erase(v);
            a.insert(t);
        }
    }
    /* cout << *a.begin(); */
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--){
        solve();
    }
}

