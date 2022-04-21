#include <bits/stdc++.h>
using namespace std; 

int main() {
    freopen("input.txt", "r", stdin);

   	int m; cin >> m;
   	multiset<int> L, R;
   	string ans[m];

   	for (int i=0; i<m; i++){
   		int n; cin >> n;
   		int count = n/2;
   		for (int j=0; j<n; j++){
   			int a; cin >> a;
   			if (L.count(a) <= R.count(a) && count){
   				ans[i] += "L";
   				L.insert(a);
   				count--;
   			}else {
   				ans[i] += "R";
   				R.insert(a);
   			}
   		}
   	}
   	if (L == R){
   		cout << "YES" << endl;
   		for (string s:ans) cout << s << endl;
   	}else {
   		cout << "NO" << endl;
   	}

   	// multiset<int>::iterator it;
   	// for (it = L.begin(); it != L.end(); ++it) cout << *it << " ";
   	// cout << endl;
   	// for (it = R.begin(); it != R.end(); ++it) cout << *it << " ";
}
