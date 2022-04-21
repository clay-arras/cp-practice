// lesson, don't be afraid to use casework or test bigger cases; also need more help implementing faster

#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

int c(int x, int n){
    return (x^(n-1));
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int> a(n/2), b(n/2);

	if (k == 0){
		for (int i=0; i<n/2; i++){
			a[i] = i;
			b[i] = c(i, n);
		}
	}

	if (k < n-1 && k > 0){
		int min_k = min(k, c(k,n));
        for(int i=0; i<n/2; i++){
            if( i != 0 && i != min_k ){
                a[i] = i;
                b[i] = c(i,n);
            }
        }

        a[0] = 0;
        b[0] = c(k,n);

        a[min_k] = k;
        b[min_k] = n - 1;
	}

	if (k == n-1){
		if (n == 4){
			cout << -1 << endl;
			return;
		}
		a[0] = n-2;
        b[0] = n-1;

        a[1] = 1;
        b[1] = n-3;

        a[2] = 0;
        b[2] = 2;

        for(int i=3; i<n/2; i++){
            a[i] = i;
            b[i] = c(i,n);
        }

	}

	for (int i=0; i<n/2; i++){
		cout << a[i] << " " << b[i] << endl;
	}
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
