#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> a;

int main() {
	/* freopen("haybales.in", "r", stdin); */
	/* freopen("haybales.out", "w", stdout); */
	cin >> N >> Q;

	for (int i=0; i<N; i++){
		int t; cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());

	while(Q--){
		int l, r; cin >> l >> r;
		cout << upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l) << endl;
	}
	
}
