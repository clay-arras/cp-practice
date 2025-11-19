// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n; cin >> n;

	int a[n];
	for (int &t : a) cin >> t;

	map<int,int> m;
	int min_dist = n+1;
 
    int prevI = 0, curI = 0;
    for (int i=0; i<n; i++) {
        if (m.find(a[i]) != m.end()) {
            curI = i;
            prevI = m[a[i]];
 
            min_dist = min((curI - prevI), min_dist);
        }
        m[a[i]] = i;
    }
	cout << n - min_dist << endl;
}

int main() {
	int N; cin >> N;
	while (N--){
		solve();
	}
}
