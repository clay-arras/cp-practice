#include <cstdio>
#include <iostream>

using namespace std;
using ll = long long;

int main(){
	#ifndef ONLINE_JUDGE
   	freopen("input.txt", "r", stdin);
   	freopen("output.txt", "w", stdout);
   #endif

	int N, Q; cin >> N >> Q;
	ll pref[N+1];

	pref[0] = 0;
	for (int i=0; i<N; i++){
		cin >> pref[i+1];
		pref[i+1] += pref[i];
	}
   
   int l, r;
   while (Q--){
      cin >> l >> r;
      cout << pref[r] - pref[l] << endl;
   }
}
