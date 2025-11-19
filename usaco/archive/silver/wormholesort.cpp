// make sure you use the right bs
#include <bits/stdc++.h>
using namespace std; 
const int MX = 1e5+5;

int N, M;
int cmp[MX];
int cows[MX];
vector<pair<int, int>> adj_list[MX];

void dfs(int s, int w, int comp){
    cmp[s] = comp;

    for (auto u : adj_list[s]){
        if (cmp[u.first] != 0 or u.second < w) continue;
        dfs(u.first, w, comp);
    }
}

bool check(int w){
    fill(cmp, cmp+N+5, 0);

    int g=1;
    for (int i=0; i<N; i++){
        if (cmp[i] == 0) dfs(i, w, ++g);
    }
    for (int i=0; i<N; i++){
        if (cmp[i] != cmp[cows[i]]) return false;
    }
    return true;
}

int bs(int lo, int hi, function<bool(int)> f) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1)/2;
		if (f(mid)) {
			lo = mid;
		}else{
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
   	/* freopen("input.txt", "r", stdin); */
   	freopen("wormsort.in", "r", stdin);
   	freopen("wormsort.out", "w", stdout);
    
    cin >> N >> M;
    for (int i=0; i<N; i++){
        int t; cin >> t;
        --t;
        cows[i] = t;
    }

    for (int i=0; i<M; i++){
        int u, v, w; cin >> u >> v >> w;
        --u, --v; 
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int mx = 1e9+20;
    int k = bs(0, mx, check);
    
    if (k == 0) k = -1;
    cout << (k >= mx - 10 ? -1 : k) << endl;
}
