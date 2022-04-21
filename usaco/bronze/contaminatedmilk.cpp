// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, D, S; cin >> N >> M >> D >> S;

	// step 1: input all data
	// step 2: find all sick people
	// 3: for all sick people find milk they drank before
	// --> array of milk and data
	// for all sick people tally up sick milk (# of sick people who drank sick milk)
	// take largest
	// 5: count all people who drank milk
	int milk_count[M] = {0};
	int sick_count[M] = {0};

	vector<vector<vector<int>>> d;
	d.resize(N);
	for (int i=0; i<N; i++){
		vector<int> arr;
		arr.resize(2);
		cin >> arr[0] >> arr[1];

		d[i].push_back(arr);
	}

	vector<vector<int>> s;
	while(cin){
		vector<int> arr;
		arr.resize(2);
		cin >> arr[0] >> arr[1];
		s.push_back(arr);
	}
	for (int i=0; i<s.size(); i++){
		for (int j=0; j<d[s[i][0]-1].size(); j++){
			if (d[s[i][0]-1][j][1] < s[i][1]){
				cout << sick_count[0];
				// cout << sick_count[d[s[i][0]-1][j][0]];
			}
		}
		// if the time of the sick person 
	}

}
