#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using str = string;

int main() {
	// #ifndef ONLINE_JUDGE
 //   		freopen("input.txt", "r", stdin);
 //   		freopen("output.txt", "w", stdout);
 //   	#endif

   	freopen("bcount.in", "r", stdin);
   	freopen("bcount.out", "w", stdout);

	int N, Q; cin >> N >> Q;
	vector<int> h(N+1, 0);
	vector<int> g(N+1, 0);
	vector<int> j(N+1, 0);

	int a;
	for (int i=0; i<N; i++){
		h[i+1] = h[i];
		g[i+1] = g[i];
		j[i+1] = j[i];

		cin >> a;
		if (a == 1) h[i+1]++;
		else if (a == 2) g[i+1]++;
		else if (a == 3) j[i+1]++;
	}

	int l, r;
	while(Q--){
		cin >> l >> r;
		cout << h[r] - h[l-1] << " ";
		cout << g[r] - g[l-1] << " ";
		cout << j[r] - j[l-1] << endl;
	}
	return 0;
}