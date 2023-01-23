#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> hay;

bool check(int R){
	int k=1, p=0;
	for (int i=0; i<N; i++){
		if (hay[i] - hay[p] > 2*R){
			k++;
			p = i;
		}
	}
	return k <= K;
}
int bs(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	cin >> N >> K;
	for (int i=0; i<N; i++){
		int t; cin >> t;
		hay.push_back(t);
	}
	sort(hay.begin(), hay.end());
	cout << bs(1, (hay[N-1] - hay[0]), check) << endl;
}
