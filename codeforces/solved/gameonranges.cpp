#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void solve(){
    int n; cin >> n;
    int l[n], r[n];
    for (int i=0; i<n; i++){
        cin >> l[i] >> r[i];
    }

    for (int i=0; i<n; i++){
        int ans=l[i];
        for (int j=0; j<n; j++){
            if (l[i]==l[j] and r[j]<r[i]){
                ans = max(ans, r[j]+1);
            }
        }
        cout << l[i] << " " << r[i] << " " << ans << "\n";
    }   
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
   	
	return 0;
}