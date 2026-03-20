#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve1() { // this doesn't work :p
    long long X; cin >> X;

    long long t = X;
    vector<long long> facts;
    for (long long i=2; i<=sqrt(X) && t != 1; i++) {
        while (t % i == 0) {
            t /= i;
            facts.push_back(i);
        }
    }
    if (t != 1) facts.push_back(t);
    sort(facts.begin(), facts.end());

    // int st = -1e9;
    int st = 0;
    vector<int> ans;
    for (long long i : facts) {
        for (int j=0; j<i-1; j++)
            ans.push_back(st);
        ++st;
    }

    cout << (int)ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}

void solve() {
    long long X; cin >> X;
    long long M = 63-__builtin_clzll(X);

    deque<int> dq;
    for (int i=0; i<M; i++) 
        dq.push_back(2*i+1);
    for (long long i=M-1; i>=0; i--) {
        if ((1LL << i) & X) 
            dq.push_front(2*(M-i));
    }
    cout << (int)dq.size() << endl;
    for (int i : dq)
        cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
