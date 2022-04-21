#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n; cin >> n;
    multiset<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.insert(t);
    }
    int ans=0;
    
    vector<int> done(n, 0);
    for (int i=1; i<=n; i++){
        if (a.count(i)){
            a.erase(a.find(i));
            done[i-1] = true;
        }
    }

    for (int i=1; i<=n; i++){
        if (!done[i-1]){
            auto it = a.lower_bound(2*i+1);
            if (it == a.end()) {
                cout << "-1" << endl;
                return;
            }else{
                ans++;
                a.erase(it);
            }
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}


