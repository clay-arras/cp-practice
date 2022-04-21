#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;
	vector<int> a(n);

	for (int &t:a) cin >> t;
	
	vector<int> odds, evens;
	for (int i=0; i<n; i++){
		if (a[i]%2) odds.emplace_back(a[i]);
		else evens.emplace_back(a[i]);
	}

	vector<int> sorted_odds = odds;
	vector<int> sorted_evens = evens;

	sort(sorted_odds.begin(), sorted_odds.end());
	sort(sorted_evens.begin(), sorted_evens.end());


	for (int i=0, len = (int)odds.size(); i<len; i++){
		if (sorted_odds[i] != odds[i]){
			cout << "NO\n";
			return;
		}
	}
	for (int i=0, len = (int)evens.size(); i<len; i++){
		if (sorted_evens[i] != evens[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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