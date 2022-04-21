// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int N, M; 
int count_adj(char a[1000][1000], int i, int j){
	int count=0;

	int dx[]{1, 1, -1, -1};
	int dy[]{-1, 1, 1, -1};

	for (int i=0; i<4; i++){
		if (a[i+dx[i]][j+dy[i]] == 'C'){
			count++;
		}
	}

	return count;
}

int main() {
	cin >> N >> M;
	char arr[1000][1000];

	for (int i=0; i<N; i++){
		string row; 
		cin >> row;
		for (int j=0; j<M; j++){
			arr[i][j] = row[j];
		}
	}

	int ans=0;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (arr[i][j] == 'G'){
				if (count_adj(arr, i, j) >= 2) ans++;
			}
		}
	}
	cout << ans << endl;
}
