#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n; cin >> n;
    int a[n]; for (int& t : a) cin >> t;
    
    int p=0, ans=0;
    for (int i=0; i<n; i++){
        if (a[i]){
            if (i-p > 1) ans += i-p;
            p = i;
        }
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
