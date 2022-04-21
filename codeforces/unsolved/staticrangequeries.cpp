#include <bits/stdc++.h>
using namespace std;

int MAX_N = 20;
void solve(){
	int N, Q; cin >> N >> Q;

	vector<int> diff(MAX_N+1, 0);
	while(N--){
		int l, r, v; cin >> l >> r >> v;
		--l, --r;
		diff[l] -= v;
		diff[r+1] += v;
	}

	vector<int> pref(MAX_N+1, 0);
	vector<int> a(MAX_N, 0);

	for (int i=1; i<MAX_N; i++){
		a[i] = a[i-1] - diff[i-1];
	}

	for (int i=0; i<MAX_N; i++){
		pref[i+1] = pref[i];
		pref[i+1] += a[i+1];
	}

	while(Q--){
		int l, r; cin >> l >> r;
		cout << pref[l] - pref[r+1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t=1;
   	while(t--){
   		solve();
   	}
	return 0;
}
