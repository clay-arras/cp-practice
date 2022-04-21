#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const int MAXN = 1000;
int n, m; 
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dm[] = {0, 0, -1, 1};
int dn[] = {1, -1, 0, 0};

void ff(int i, int j){
	if (i < 0 or i >= n or j < 0 or j >= m
		or grid[i][j] == '#'
		or visited[i][j]
		)return;

	visited[i][j] = true;
	for (int t=0; t<4; t++){
		ff(i+dm[t], j+dn[t]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	cin >> n >> m;
   	for (int i=0; i<n; i++){
   		string s; cin >> s;
   		for (int j=0; j<m; j++){
   			grid[i][j] = s[j];
   		}
   	}
   	int ans=0;
   	for (int i=0; i<n; i++){
   		for (int j=0; j<m; j++){
   			if (!visited[i][j] and grid[i][j] == '.'){
   				ff(i, j);
   				ans++;
   			}
   		}
   	}
   	cout << ans << "\n";
}