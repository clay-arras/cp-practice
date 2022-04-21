// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
vector<string> chars[100];
int num_common(int i, int j){
	vector<string> &v1 = chars[i], &v2 = chars[j];
	int count = 0;
	for (int n=0; n<(int)v1.size(); n++){
		for (int m=0; m<(int)v2.size(); m++){
			if (v1[n] == v2[m]) count++;
		}
	}
	return count;
}


int main() {
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	int N; cin >> N;
	// chars.resize(N);

	string c; int n;
	for (int i=0; i<N; i++){
		cin >> c >> n;
		for (int j=0; j<n; j++){
			cin >> c;
			chars[i].push_back(c);
		}
	}

	int max_inter = 0; 
	for (int i=0; i<N; i++){
		for (int j=i+1; j<N; j++){
			max_inter = max(max_inter, num_common(i, j));
		}
	}
	cout << max_inter+1 << endl;

}
