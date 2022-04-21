#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5+5;
long long x_0, y_0, xF, yF;
long long len; string s;

struct coords{long long x=0, y=0;};
coords cds[MX];

string mv = "UDLR";
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool check(long long days){
    long long cnt = days/len, rem = (days+len)%len;
    long long x = cnt*cds[len].x + cds[rem].x + x_0;
    long long y = cnt*cds[len].y + cds[rem].y + y_0;

    return abs(xF - x) + abs(yF - y) <= days;
}

long long bs(long long lo, long long hi, function<bool(long long)> f) {
	hi++;
	while (lo < hi){
		long long mid = lo + (hi - lo)/2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main(){
    ios:: sync_with_stdio(0), cin.tie(0);
    /* freopen("io/input.txt", "r", stdin); */

    cin >> x_0 >> y_0 >> xF >> yF;    
    cin >> len >> s;
    
    for (long long i=1; i<=len; i++){
        cds[i] = cds[i-1];
        int ort;
        for (int j=0; j<4; j++){
            if (s[i-1] == mv[j]) ort = j;
        }
        cds[i].x += dx[ort];
        cds[i].y += dy[ort];
    }
    long long ans = bs(0, 1e17, check);
    if (ans > 5e16) cout << -1 << endl;
    else cout << ans << endl;

}
