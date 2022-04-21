#include <bits/stdc++.h>
using namespace std;

int n, at, def;
int sum=0;
vector<int> h; // ms

int cost(int i){ return abs(min(0, h[i]-def) + min(0, (sum - h[i])-at)); }
void solve(){
    cin >> n;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        h.push_back(t);
        sum += t;
    }
    sort(h.begin(), h.end());

    int m; cin >> m;
    while(m--){
        cin >> def >> at;

        /* int lo = 1, hi = n-1; */
        /* while (lo < hi){ */
        /*     int mid = (hi+lo)/2; */
        /*     if (cost(mid - 1) < cost(mid)){ */
        /*         hi = mid-1; */
        /*     }else{ */
        /*         lo = mid+1; */
        /*     } */
        /* } */
        /* cout << cost(lo-1) << endl; */
        // need bs implementation library pls
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t=1;
   	while(t--){
   		solve();
   	}
}
