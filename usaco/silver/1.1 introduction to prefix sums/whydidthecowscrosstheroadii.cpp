#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
   		freopen("input.txt", "r", stdin);
   		freopen("output.txt", "w", stdout);
   	#endif

	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

   	int N, K, B; cin >> N >> K >> B;
   	vector<int> sig(N+1, 0);

   	int a; 
   	while (B--){
   		cin >> a;
   		sig[--a]++;
   	}

   	for(int i=0; i<N; i++){
   		sig[i+1] += sig[i];
   	}

   	int ans=INT_MAX;
   	for (int i=0; i<N-K; i++){
   		ans = min(ans, sig[i+K]-sig[i]);
   	}

   	cout << ans << endl;
	return 0;
}