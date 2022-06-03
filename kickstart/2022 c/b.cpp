#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

bool** dp;
bool found = false;
vector<int> d(0);
void printSubsetsRec(vector<int> arr, int i, int sum, vector<int>& p) {
    debug(sum);
    int s = 0;
    for (int t : d) s += t;
    if (s == sum){
        found = true;
        debug(d, p);
    }
    debug(s, sum);
    if (found) {
        debug(0);
        return;
    }

    if (i == 0 && sum != 0 && dp[0][sum]) {
        p.push_back(arr[i]);
        if (arr[i] == sum) d = p;
        return;
    }

    if (i == 0 && sum == 0) {
        d = p;
        return;
    }

    if (dp[i-1][sum]) {
        vector<int> b = p;
        printSubsetsRec(arr, i-1, sum, b);
    }

    if (sum >= arr[i] && dp[i-1][sum-arr[i]]) {
        p.push_back(arr[i]);
        printSubsetsRec(arr, i-1, sum-arr[i], p);
    }
}

void printAllSubsets(vector<int> arr, int n, int sum) {
    if (n == 0 || sum < 0) return;

    dp = new bool*[n];
    for (int i=0; i<n; ++i) {
        dp[i] = new bool[sum + 1];
        dp[i][0] = true;
    }

    if (arr[0] <= sum) dp[0][arr[0]] = true;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || dp[i-1][j-arr[i]] : dp[i - 1][j];

    if (dp[n-1][sum] == false) {
        cout << "error" << endl;
        return;
    }

    vector<int> p;
    printSubsetsRec(arr, n-1, sum, p);
}


void solve(){
    int n, x, y; cin >> n >> x >> y;
    int sum = n*(n+1)/2;

    if (sum % (x+y)){
        cout << "IMPOSSIBLE\n";
        return;
    }else cout << "POSSIBLE\n";

    int f = sum / (x+y);
    vector<int> a;
    for (int i=1; i<=n; i++) a.push_back(i);
    printAllSubsets(a, n, x*f);

    cout << (int)d.size() << "\n";
    for (int i : d) cout << i << " ";
    cout << "\n";

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
   	for(int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
   		solve();
   	}
}
