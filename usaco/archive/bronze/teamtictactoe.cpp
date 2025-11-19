// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
char b[3][3];
int same[26];

bool two_eq(char a, char b, char c){
	if ((a == b && a != c) || (a == c && a != b) || (c == b && b != a)) return true;
	else return false;
}
bool isIn(char a, string arr){
	for (int i : arr) if (i == a) return true;
	return false;
}

int main() {
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	// each team can only win once

	int same(0), two(0);
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) cin >> b[i][j];
	}

	for (int i=0; i<3; i++){
		if (b[0][i] == b[1][i] && b[0][i] == b[2][i]) same++;
		if (b[i][0] == b[i][1] && b[i][0] == b[i][2]) same++;

		if (two_eq(b[0][i], b[1][i], b[2][i])) two++;
		if (two_eq(b[0][i], b[1][i], b[2][i])) two++;
	}

	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]  && b[0][0] == b[2][2]) same++;
	if (b[2][0] == b[1][1] && b[1][1] == b[0][2]  && b[2][0] == b[0][2]) same++;

	if (two_eq(b[0][0], b[1][1], b[2][2])) two++;
	if (two_eq(b[2][0], b[1][1], b[2][0])) two++;

	cout << same << endl << two << endl;
}
