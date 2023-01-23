// long longs are the death of me. make sure to long long everything that is an int
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> x;

long long bs(long long lo, long long hi, function<bool(long long)> f) {
	hi++;
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

bool check(long long m){
    long long sum=0, groups=0;
    for (int i=0; i<n; i++){
        if (x[i] > m) return false;
        if (sum + x[i] > m){
            groups++;
            sum = x[i];
        }else{
            sum += x[i];
        }
    }
    if (sum > 0) groups++;
    return groups <= k;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    /* freopen("io/input.txt", "r", stdin); */

    cin >> n >> k;
    long long maxs = 0;
    for (int i=0; i<n; i++){
        long long t; cin >> t;
        x.push_back(t);
        maxs += t;
    }
    cout << bs(0, maxs, check) << endl;
}
