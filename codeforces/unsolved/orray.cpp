#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

template<std::size_t N>
bool operator<(const std::bitset<N>& x, const std::bitset<N>& y)
{
    for (int i = N-1; i >= 0; i--) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

const int MX = 32;
void solve(){
    int n; cin >> n;
    vector<int> bit[MX];

    for (int i=0; i<n; i++){
        int t; cin >> t;
        for (int j=0; j<MX; j++){
            if ((t >> j) & 1){
                bit[j].push_back(t);
            }
        }
    }
    for (int i=0; i<8; i++){
        cout << i+1 << " ";
        debug(bit[i]);
    }

    bitset<32> b(0);
    for (int i=MX; i>=0; i--){
        bitset<32> m = b;
        for (int v : bit[i]){
            if (m < v | b){

            }
        }
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}
