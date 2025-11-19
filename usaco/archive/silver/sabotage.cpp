#include <bits/stdc++.h>
using namespace std;

int N; int p, q;
vector<int> prod;

float check(int m){
	float sum = p+q;
	for (int i=0; i<m; i++){
		sum += prod[i];
	}
	return sum/(m+2);
}


int main() {
	// freopen("sabotage.in", "r", stdin);
	// freopen("sabotage.out", "w", stdout);
	cin >> N;
	for (int i=0; i<N; i++){
		int t; cin >> t;

		if (i == 0) p = t;
		else if (i == N-1) q = t;
		else prod.push_back(t);
	}
	// cout << p << " " << q << endl;
	// for (int& t : prod) cout << t << " ";
	// sort(prod.begin(), prod.end());
	// cout << check(N-2) << endl;
	int x = -1;
	for (int b = N-2; b >= 1; b /= 2) {
		while (check(x+b) >= check(x+b+1)) x += b;
	}
	int k = x+1;
	cout << round(check(k)*1000.0)/1000.0 << endl;
	// for (int i=0; i<=N-2; i++){
		// cout << check(i) << endl;
	// }
}
