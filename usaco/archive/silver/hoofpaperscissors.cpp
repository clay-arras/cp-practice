#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
   		freopen("input.txt", "r", stdin);
   		freopen("output.txt", "w", stdout);
   	#endif

	// freopen("hps.in", "r", stdin);
	// freopen("hps.out", "w", stdout);

	int N; cin >> N;
	vector<int> p(N+1, 0);
	vector<int> s(N+1, 0);
	vector<int> h(N+1, 0);

	char a;
	for (int i=0; i<N; i++){
		p[i+1] = p[i];
		s[i+1] = s[i];
		h[i+1] = h[i];

		cin >> a;
		if (a == 'P') p[i+1]++;
		else if (a == 'S') s[i+1]++;
		else if (a == 'H') h[i+1]++;
	}
	int ans=0;

	for (int k=1; k<=N; k++){
		ans = max(ans, p[k] + s[N]-s[k]);
		ans = max(ans, p[k] + h[N]-h[k]);
		ans = max(ans, s[k] + p[N]-p[k]);
		ans = max(ans, s[k] + h[N]-h[k]);
		ans = max(ans, h[k] + p[N]-p[k]);
		ans = max(ans, h[k] + s[N]-s[k]);
	}

	cout << ans << endl;
	return 0;
}

