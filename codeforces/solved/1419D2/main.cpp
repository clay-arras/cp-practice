#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

/*
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    sort(A.rbegin(), A.rend());
    deque<int> cp(A.begin(), A.end()), pl(A.begin(), A.end());
    unordered_map<int, int> cnt;
    for (int i : A)
        cnt[i]++;

    int l, r = pl.front(); pl.pop_front();
    cnt[r]--;

    int ans = 0;
    vector<int> con = {r};

    for (int i = 0; i < N; i++) { 
        while (!pl.empty() && cnt[pl.front()] == 0)
            pl.pop_front();
        if (pl.empty()) break;

        l = r;
        r = pl.front(); pl.pop_front();
        cnt[r]--;

        while (!cp.empty() && (cnt[cp.front()] == 0 || cp.front() >= r))
            cp.pop_front();

        if (cp.empty()) {
            cnt[r]++; 
            break;   
        }
        
        int c = cp.front(); cp.pop_front();
        cnt[c]--;

        ans++;
        con.push_back(c);
        con.push_back(r);
    }

    for (auto [k, v] : cnt) {
        for (int j = 0; j < v; j++)
            con.push_back(k);
    }
    cout << ans << endl;
}
*/

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;
    
    sort(A.begin(), A.end());
    vector<int> cp(A.begin(), A.begin() + N/2);
    vector<int> pl(A.begin() + N/2, A.end());
    pl.push_back(2e-9);

    vector<int> con = {pl[0]};
    for (int i=0; i<(int)cp.size(); i++) {
        con.push_back(cp[i]);
        con.push_back(pl[i+1]);
    }
    int ans = 0;
    for (int i=1; i<(int)con.size()-1; i++) {
        if (con[i-1] > con[i] && con[i+1] > con[i])
            ans++;
    }
    
    cout << ans << endl;
    for (int i=0; i<N; i++)
        cout << con[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}

/*

case: 4 3 2 1 1
in this case, our greedy doesn't work because we assume that the "levels" will
always be the same
at the end, if we have a trail of ones, then the equals case constraint means
our greedy blows up

the solution addresses this because sorting means everything in the left array
is <= the right; if the first of both are the same (invalid), then it wasn't
possible in the first place
*/
