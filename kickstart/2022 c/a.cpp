#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char uletters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
char schars[] = {'#', '@', '*', '&'};

set<char> l(letters, letters+26);
set<char> ul(uletters, uletters+26);
set<char> n(numbers, numbers+10);
set<char> sc(schars, schars+4);

void solve(){
    int N; cin >> N;
    string s; cin >> s;

    int lc = 0, ulc = 0, nc = 0, scc = 0;
    for (int i=0; i<N; i++){
        if (l.count(s[i])) lc++;
        else if (ul.count(s[i])) ulc++;
        else if (n.count(s[i])) nc++;
        else if (sc.count(s[i])) scc++;
    }

    if (!lc) s += 'a';
    if (!ulc) s += 'A';
    if (!nc) s += '0';
    if (!scc) s += '#';

    while ((int)s.size() < 7) s += 'A';
    cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
   	for(int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
   		solve();
   	}
}
