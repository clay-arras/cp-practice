#include <bits/stdc++.h>
using namespace std; 

int n, k;
vector<int> a;

int bs(int lo, int hi, function<bool(int)> f){
	lo--;
	while (lo < hi){
		int mid = lo + (hi - lo + 1)/2;
		if (f(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("./io/input.txt", "r", stdin);
        
    cin >> n >> k;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    cout << max(a[n/2], bs(0, a[n/2] + k, [](int m){
        long long sum=0;
        for (int i=n/2; i<n; i++){
            if (m - a[i] > 0) sum += m - a[i];
            else break;
        }
        return sum <= k;
    })) << "\n";
}	
