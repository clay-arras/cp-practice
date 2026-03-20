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
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    long long sum = 0;
    for (int i=0; i<N; i+=2)
        sum += A[i];
    
    vector<long long> off1;
    for (int i=0; i<N; i+=2) {
        if (i+1<N) 
            off1.push_back(A[i+1]-A[i]);
    }

    vector<long long> off2;
    for (int i=2; i<N; i+=2) {
        if (i-1>=0) 
            off2.push_back(A[i-1]-A[i]);
    }

    long long gain = 0, roll = 0;
    for (long long i : off1) {
        roll = max(0LL, roll + i);
        gain = max(gain, roll);
    }
    roll = 0;
    for (long long i : off2) {
        roll = max(0LL, roll + i);
        gain = max(gain, roll);
    }
    cout << sum + gain << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
