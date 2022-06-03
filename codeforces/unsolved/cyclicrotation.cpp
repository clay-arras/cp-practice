#include <bits/stdc++.h>
using namespace std;

#define cerr if(0) cerr
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

void cope() {
    int n; cin >> n;
    vector<int> a, b;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    for (int i=0; i<n; i++){
        int t; cin >> t;
        b.push_back(t);
    }

    vector<pair<int, int> > ap, bp;
    int cnt = 1;
    for (int i=1; i<n; i++){
         if (a[i-1] != a[i]){
             ap.push_back(make_pair(a[i-1], cnt));
             cnt = 1;
         }else cnt++;
    }
    ap.push_back(make_pair(a[n-1], cnt));
    cnt = 1;
    for (int i=1; i<n; i++){
         if (b[i-1] != b[i]){
             bp.push_back(make_pair(b[i-1], cnt));
             cnt = 1;
         }else cnt++;
    }
    bp.push_back(make_pair(b[n-1], cnt));

    vector<int> at(n, 0), bt(n, 0);
    int j = 0; int apl = (int)ap.size(), bpl = (int)bp.size();
    for (int i=0; i<bpl; i++){
        bt[bp[i].first-1] += bp[i].second;

        do{ at[ap[j].first-1] += ap[j].second;
        }while (ap[j].first != bp[i].first and ++j < apl);

        if ((j == apl-1 and i != bpl-1) or
                (bt[bp[i].first-1] > at[bp[i].first-1])){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a, b;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(--t);
    }
    for (int i=0; i<n; i++){
        int t; cin >> t;
        b.push_back(--t);
    }

    vector<int> at(n, 0), bt(n, 0);
    for (int i=0, j=0; i<n; i++){
        debug(bt, at)
        if (bt[b[i]] > at[b[i]]){
            cerr << "NO" << endl;
            return;
        }
        debug(a, b)
        debug(i, j)

        while(b[i] != a[j] and j < n){
            j++, at[a[j]]++;
        }
        bt[b[i]]++;
    }
    cerr << "YES" << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    /* int clog_ = clock(); */
	ios::sync_with_stdio(0), cin.tie(0);

    int t; cin >> t;
    while (t--){
        solve();
    }
    /* cerr << "Time: " << (int)((clock()-clog_)*1.0/CLOCKS_PER_SEC * 1000) << "ms\n"; */
}
