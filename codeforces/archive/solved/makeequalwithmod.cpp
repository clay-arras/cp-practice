#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    set<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.insert(t);
    }

    bool cs = false;
    for (auto it = ++a.begin(); it != a.end(); it++){
        auto itt = it;
        itt--;
        if (*it - *itt == 1){
            cs = true;
            break;
        }
    }

    if (!a.count(1)){
        cout << "yES" << endl;
    }else if (a.count(1) and !cs){
        cout << "YeS" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */

    int t; cin >> t;
    while(t--){
        solve();
    }
}
