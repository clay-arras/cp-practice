/*
Problem: Find prefix subgroups of an array so that the MEX of each is the lexigraphical largest (must remove subgroup after operation).
Algorithm: Make a 2d array of the locations of each number. Keep track of which you've seen, mark it off when you have. Keep track of the largest one in the subgroup so that you can ++i to catch up when you've pushed back a new MEX subgroup. 
Implementation: 2d array of locs, use of arrays in general.

1628A Div 1
*/

#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for (int &t:a) cin >> t;

    vector<vector<int>> loc(n+1);
    for (int i=0; i<n; i++){ 
       loc[a[i]].pb(i); 
    }
	vector<int> seen(n+1);
    vector<int> ans;

    int i=0, j=-1, mex=0; // Why is j -1? Ans = don't question it
    while (i<n){
        if (seen[mex] < (int)loc[mex].size()){ 
           j = max(j, loc[mex][seen[mex]]);
           mex++;
        }else{ 
            if (j<i) j++; // No idea what this does
            ans.pb(mex), mex=0;
            while (i<=j) ++seen[a[i++]];
        }
    }


    cout << (int)ans.size() << "\n";
    for (int &t : ans) cout << t << " ";

    cout << "\n";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
   	
	return 0;
}
