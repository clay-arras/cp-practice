/*
Problem: Make the sum of each subset of an array equal to the first and last edges of the array times the number of elements in the subset, ie ar + ... al = (ar+al)/2 * (l-r+1)
Algoritm: Notice all valid sequences it is an arithmetic progression. Then complete search, fixing two elements and then checking if each element is in the ap
Pitfalls:
- Avoid division when you can, try to always multiply it out
- What makes an arrangement valid?

1616C
*/

#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;
	int a[n];
	for (int &t:a) cin >> t;

	if (n==1){
		cout << 0 << "\n";
		return;
	}

	int ans=0, counter, dp, dq;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			counter=0;
			dp=a[j]-a[i];
      		dq=j-i;

      		for (int k=0; k<n; k++){
				if (a[j]*dq + dp*(k-j) == a[k]*dq) counter++;
			}
			ans = max(ans, counter);
		}
	}
	cout << n-ans << "\n";
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