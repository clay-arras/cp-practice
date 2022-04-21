// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int time_interval[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);

	int N; cin >> N;
	int start[N], end[N];

	for (int i=0; i<N; i++){
		cin >> start[i] >> end[i];
		for (int j=start[i]; j<end[i]; j++){
			time_interval[j]++;
		}
	}
	int total_covered = 0;
	for (int i:time_interval){
		if (i > 0) total_covered++;
	}
	int min_cov(total_covered), count;
	for (int i=0; i<N; i++){
		count = 0;
		for (int j=start[i]; j<end[i]; j++){
			if (time_interval[j] <= 1) count++;
		}
		min_cov = min(min_cov, count);
	}
	cout << total_covered - min_cov << endl;
	
}




