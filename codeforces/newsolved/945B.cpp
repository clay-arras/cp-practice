#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int N;
vector<int> A;
const int mxP = 21;
bool ok(int k) {
    vector<int> bits(mxP, 0);

    for (int i=0; i<k; i++)
        for (int j=0; j<mxP; j++)
            bits[j] += (bool)(A[i] & (1 << j));

    bool ans = true;
    for (int i=k; i<N; i++) {
        for (int j=0; j<mxP; j++) {
            int prev = (bool)(A[i-k] & (1 << j));
            int curr = (bool)(A[i] & (1 << j));
            if (bits[j] > 0 && bits[j] - prev + curr == 0)
                ans &= false;
            if (bits[j] == 0 && bits[j] - prev + curr > 0)
                ans &= false;
            bits[j] -= prev;
            bits[j] += curr;
        }
    }
    return ans;
}

template<class T>
T firstTrue(T l, T r) {
    r++;
    while (l < r) {
        T mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() {
    cin >> N;

    A = vector<int>(N);
    for (int& i : A)
        cin >> i;

    cout << firstTrue(1, N) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*



*/
