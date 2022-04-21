// almost solved, tle on last test case; will come back later
#include <bits/stdc++.h>
using namespace std;

int N, T_max; 
vector<int> dur;

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
	/* freopen("cowdance.in", "r", stdin); */
	/* freopen("cowdance.out", "w", stdout); */

    freopen("io/input.txt", "r", stdin);
	cin >> N >> T_max;

	for (int i=0; i<N; i++){
		int t; cin >> t;
		dur.push_back(t);
	}
    auto check = [](int k){
		int a[k];
		fill(a, a+k, 0);
		for (int i=0; i<N; i++){
            sort(a, a+k);
			a[0] += dur[i];
		}
		sort(a, a+k);
        /* for (int t : a)cout << t << " "; */
        /* cout << endl; */
        cout << a[k-1] << " " << a[k-2] << endl;
		return a[k-1] <= T_max;
	};

    auto check1 = [](int k){
        set<int> a;
        for (int i=0; i<k; i++){
            a.insert(dur[i]);
        }
        for (int i=k; i<N; i++){
            int first = *a.begin();
            a.erase(a.begin());
            a.insert(first + dur[i]);
        }
        /* for (auto t : a) cout << t << " "; */
        /* cout << endl; */
        cout << *a.rbegin() << endl;;
        return *a.rbegin() <= T_max;
    };
	cout << bs(1, N, check1) << endl << endl;
	cout << bs(1, N, check) << endl;

}
