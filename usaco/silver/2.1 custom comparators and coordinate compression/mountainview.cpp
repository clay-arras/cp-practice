#include <bits/stdc++.h>
using namespace std; 

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first != b.first) return a.first < b.first;
	else return a.second > b.second;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

   	int N; cin >> N;
   	vector<pair<int, int>> ranges(N);

   	for (int i=0; i<N; i++){
   		int x, y; cin >> x >> y;
   		ranges[i].first = x-y;
   		ranges[i].second = x+y;
   	}
   	sort(ranges.begin(), ranges.end(), cmp);

   	int big=-1, ans=0;
   	for (int i=0; i<N; i++){
   		if (big >= ranges[i].second) ans++;
   		big = max(big, ranges[i].second);
   	}
   	cout << N-ans << "\n";

}