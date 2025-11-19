#include <bits/stdc++.h>
using namespace std;

long long N, M;
vector<pair<long long, long long>> intv;

bool check(long long dist){
	long long pos=0;
	long long k=0;
	
	for (int i=0; i<M; i++){
		pos = max(intv[i].first, pos);
		while(pos <= intv[i].second){
			k++;
			pos += dist;
		}
	}
	return k >= N;
}

int bs(long long lo, long long hi, function<bool(int)> f) {
	lo--;
	while (lo < hi) {
		long long mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);

	cin >> N >> M;
	for (int i=0; i<M; i++){
		long long u, v; cin >> u >> v;
		intv.push_back({u, v});
	}
	sort(intv.begin(), intv.end());

	cout << bs(1, intv[M-1].second, check) << endl;

}
