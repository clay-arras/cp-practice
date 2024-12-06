#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

map<int, int> m;
void primeFactors(int n) {
    while (n % 2 == 0) {
        m[2]++;
        n = n/2;
    }
    for (int i=3; i<=sqrt(n); i+=2) {
        while (n % i == 0) {
            m[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        m[n]++;
}

void solve() {
    int N; cin >> N;
    primeFactors(N);

    int ans = 0;
    for (int i=0; i<sqrt(N); i++) {
        int sum = 1;
        for (auto t : m) {
            if (m[t.first] == 0)
                continue;
            sum *= t.first;
            m[t.first]--;
        }
        if (sum == 1)
            break;
        ans += sum;
    }

    cout << ans << endl;
    m.clear();
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

Prime factorize number
Greedy: always best to multiply all the prime factors

*/
