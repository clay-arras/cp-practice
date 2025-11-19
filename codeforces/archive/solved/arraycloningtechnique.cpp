#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
    vector<int> a;

	for (int i=0; i<n; i++){
		int t; cin >> t;
        a.push_back(t);
	}
    sort(a.begin(), a.end());

    int mx=1, cnt=1;
    for (int i=1; i<n; i++){
        if (a[i] != a[i-1]){
            mx = max(mx, cnt);
            cnt = 1;
            continue;
        }
        cnt++;
    }
    mx = max(mx, cnt);

    int ans=n-mx;
    while (mx < n){
        mx *= 2;
        ans++;
    }
    cout << ans << endl;
}
int main() {
    /* freopen("input.txt", "r", stdin); */

	int t; cin >> t;
	while(t--){
		solve();
	}
}
