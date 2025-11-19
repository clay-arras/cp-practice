// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, N; cin >> K >> N;
	map <string, int> names;
	char ans[N][N]; string papers[K][N];

	string name;
	for (int i=0; i<N; i++){
		cin >> name;
		names.insert(pair<string, int> (name, i));
	}
	for (int i=0; i<K; i++){
		for (int j=0; j<N; j++){
			cin >> papers[i][j];
		}
	}

	for (int i=0; i<N; i++) for (int j=0; j<N; j++) ans[i][j] = '_';1


	string p_1, p_2;
	for (int i=0; i<K; i++){
		for (int j=0; j<N-1; j++){
			p_1 = papers[i][j];
			p_2 = papers[i][j+1];
			if (p_1 < p_2){
				// if (ans[names[p_1]][names[p_2]] != '0' && ans[names[p_2]][names[p_1]] != '0'){
				// 	ans[names[p_2]][names[p_1]] = '?';
				// 	ans[names[p_1]][names[p_2]] = '?';
				// }
				// cout << p_1 << p_2 << " p1"<< endl;
			}
			if (p_1 > p_2){
				// cout << p_1 << p_2 << " p2" << endl;

				ans[names[p_1]][names[p_2]] = '1';
				ans[names[p_2]][names[p_1]] = '0';

				for (int k=0; k<N; k++){
					if(ans[names[p_1]][k] == '?'){
						ans[names[p_2]][k] = '1';
						ans[k][names[p_2]] = '0';
					}
				}
			}
		}
	}


	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (i!=j){
				cout << ans[i][j];
			} else {
				cout << 'B';
			} 
		}
		cout << endl;
	}




}
