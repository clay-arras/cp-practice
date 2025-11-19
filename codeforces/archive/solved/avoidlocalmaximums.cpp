#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void solve(){
	int n; cin >> n;
	vector<int> a(n);

	for (int &t:a) cin >> t;

	vector<int> loc_max;
	for (int i=1; i<n-1; i++){
		if (a[i] > a[i-1] and a[i] > a[i+1]){
			loc_max.pb(i);
		}
	}
	int ops=0, len=(int)loc_max.size(), i;
	int sandw=false;
	for (i=0; i<len-1; i++){
		if (loc_max[i+1] - loc_max[i] == 2){
			a[loc_max[i]+1] = max(a[loc_max[i]], a[loc_max[i+1]]);
			i++, ops++;
			if (i >= len-1) sandw=true;
		}else{
			a[loc_max[i]] = max(a[loc_max[i]-1], a[loc_max[i]+1]);
			ops++;
		}
	}
	if (!sandw and len){
		a[loc_max[len-1]] = max(a[loc_max[len-1]-1], a[loc_max[len-1]+1]);
		ops++;
	}

	cout << ops << "\n";
	for (int &t:a) cout << t << " ";
	cout << "\n";
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