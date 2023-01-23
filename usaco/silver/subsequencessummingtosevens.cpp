
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //   		freopen("input.txt", "r", stdin);
 //   		freopen("output.txt", "w", stdout);
 //   	#endif
   	
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int N; cin >> N;
	vector<int> first(7, -1);

	int ans = 0; 
	int c, v;
	for (int i=0; i<N; i++){
		cin >> c;
		v = (v+c)%7;
		if (first[v] == -1){
			first[v] = i;
		}else{
			ans = max(ans, i - first[v]);
		}
	}
    cout << ans << endl;
}
