// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int alph[26];

int main() {
	string guess[3];
	string ans[3];

	// input
	string a;
	for (int i=0; i<3; i++){
		cin >> a;
		ans[i] = a;
	}
	for (int i=0; i<3; i++){
		cin >> a;
		guess[i] = a;
	}

	// counting number of each letter
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			alph[ans[i][j] - 'A']++;
		}
	}

	int green=0, yellow=0;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (guess[i][j] == ans[i][j]){
				green++;
				alph[guess[i][j]-'A']--;
			} else if (alph[guess[i][j]-'A'] => 0){
				yellow++;
				alph[guess[i][j]-'A']--;
			}
		}
	}
	cout << green << endl << yellow << endl;;

}
