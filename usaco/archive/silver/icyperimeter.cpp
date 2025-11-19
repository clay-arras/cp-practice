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
int n;
int area, perimeter;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void ff(int i, int j){
	if (i < 0 or i >= n or j < 0 or j >= n or grid[i][j] == '.'){
		perimeter++;
		return;
	}else if (visited[i][j]){
		return;
	}

	visited[i][j] = true;
	area++;
	for (int t=0; t<4; t++){
		ff(i+dx[t], j+dy[t]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

   	cin >> n;
   	for (int i=0; i<n; i++){
   		string s; cin >> s;
   		for (int j=0; j<n; j++){
   			grid[i][j] = s[j];
   		}
   	}
   	int max_a=0, min_p=0;
   	for (int i=0; i<n; i++){
   		for (int j=0; j<n; j++){
   			if (!visited[i][j] and grid[i][j] == '#'){
   				area = perimeter = 0;
   				ff(i, j);

   				if (area == max_a) min_p = min(min_p, perimeter);
   				else if (area > max_a){
   					max_a = area;
   					min_p = perimeter;
   				}
   			}
   		}
   	}
   	cout << max_a << " " << min_p << "\n";
}
