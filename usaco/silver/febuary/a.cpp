#include <bits/stdc++.h>
using namespace std; 

const int MAX = 500;
int n; 
int best_pref, curr_cow;
vector<bool> visited;
vector<pair<int, int>> adj_list[MAX];

int pref_list[MAX][MAX];
int where_index[MAX];
pair<int, int> sorted_preflist[MAX][MAX];

void dfs(int s, int parent=-1){
	if (parent == -1) visited[s] = true;
	for (auto t : adj_list[s]){
		if (t.first == parent){
			visited[s] = true;
		}
	}
	if (!visited[s]) return;
	best_pref = min(best_pref, sorted_preflist[curr_cow][s].second);

	cout << s << "th node, parent: " << parent << " , neighbors :";
	for (auto t:adj_list[s]) cout << t.first << " ";
	cout << endl;
	for (auto t : adj_list[s]){
		if (!visited[t.first]){
			dfs(t.first, s);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> pref_list[i][j];
			sorted_preflist[i][j].first = i+1;
			sorted_preflist[i][j].second = pref_list[i][j]; 

			if (pref_list[i][j] == i+1){
				where_index[i] = j;
			}
		}
	}
	for (int i=0; i<n; i++){
		sort(sorted_preflist[i], sorted_preflist[i]+n);
	}

	for (int i=0; i<n; i++){
		int index = where_index[i];
		for (int j=0; j<index; j++){
			adj_list[i].push_back(make_pair(pref_list[i][j]-1, j));
		}
	}

	for (int i=0; i<n; i++){
		visited.assign(n, false);
		best_pref = MAX+1;
		curr_cow = i;

		dfs(i);
		cout << pref_list[i][best_pref-1] << "\n";
	}
}
