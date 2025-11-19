#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    long long pos=0, neg=0;
    for (int i=0; i<N; i++)
        (s[i] == '+' ? pos++ : neg++);

    int q; cin >> q;
    while (q--) {
        long long a, b; cin >> a >> b;
        long long t = pos - neg;

        long long n = t * b;
        long long d = b - a;
        if (a == b) {
            cout << (!t ? "YES" : "NO") << endl;
        } else {
            if (n % d != 0) cout << "NO" << endl;
            else {
                if (n/d >= -neg and n/d <= pos) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// k(y − x) = (pos - neg)·y
// (pos-neg)*y % (y-x)
//
//
// Wrong because constraints aren't met
// a*x_1 + b*x_2 = a*y_1 + b*y_2
//
// a, b are buttons
// x_1+x_2 = pos
// y_1+y_2 = neg
//
//
// a(x_1 - y_1) = -b(x_2 - y_2)
// b*x_2 (mod a) == b*y_2 (mod a)
//
// x_2 (mod a) == y_2 (mod a)
// x_1 (mod b) == y_1 (mod b)
// x_2 - y_2 = a*p
// x_1 - y_1 = b*q
//
// x_2 - y_2 + x_1 - y_1 = b*q + a*p
// pos - neg = a*p + b*q
// gcd(a, b) | (pos-neg)
//
// x_1+x_2 = pos
// y_1+y_2 = neg
//
//
// 1: 3, 7
// +-+---+-
// 11211121
// 1+2+2=5
// 1+1+1+1+1=5
