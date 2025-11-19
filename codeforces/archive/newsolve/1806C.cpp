#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

/* void comb(int N, int K) { */
/*     string bitmask(K, 1); */
/*     bitmask.resize(N, 0); */
/*     map<int, char> m; */
/*     do { */
/*         set<int> add, mul; */
/*         for (int i=0; i<N; ++i) */
/*             (bitmask[i] ? add.insert(i) : mul.insert(i)); */
/*         for (int i : add) cout << (char)(i+'a'); */
/*         cout << "="; */
/*         for (int i : mul) cout << (char)(i+'a'); */
/*         cout << endl; */
/*     } while (std::prev_permutation(bitmask.begin(), bitmask.end())); */
/* } */

void solve() {
    int N; cin >> N;

    vector<int> A(2*N);
    for (int& t : A)
        cin >> t;

    cout << A << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

a+b+c=def,a+b+d=cef,a+b+e=cdf,a+b+f=cde,a+c+d=bef,a+c+e=bdf,a+c+f=bde,a+d+e=bcf,a+d+f=bce,a+e+f=bcd,b+c+d=aef,b+c+e=adf,b+c+f=ade,b+d+e=acf,b+d+f=ace,b+e+f=acd,c+d+e=abf,c+d+f=abe,c+e+f=abd,d+e+f=abc
a+b=cd,a+c=bd,a+d=bc,b+c=ad,b+d=ac,c+d=ab

*/
