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

int n;
const int MX = 1e5+5;

int xv[(MX << 2)];
int yv[(MX << 2)];

int sumx(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += xv[a++];
        if (b % 2 == 0) s += xv[b--];
        a /= 2; b /= 2;
    }
    return s;
}
void addx(int k, int x) {
    k += n;
    xv[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        xv[k] = xv[2*k]+xv[2*k+1];
    }
}
int sumy(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += yv[a++];
        if (b % 2 == 0) s += yv[b--];
        a /= 2; b /= 2;
    }
    return s;
}
void addy(int k, int y) {
    k += n;
    yv[k] += y;
    for (k /= 2; k >= 1; k /= 2) {
        yv[k] = yv[2*k]+yv[2*k+1];
    }
}

void solve(){
    int q; cin >> n >> q;

    while(q--){
        int t; cin >> t;
        debug(n, xv, yv);
        if (t == 1){
            int x, y; cin >> x >> y;
            --x, --y;
            addx(n+x, 1);
            addy(n+y, 1);

        }else if (t == 2){
            int x, y; cin >> x >> y;
            --x, --y;
            addx(n+x, -1);
            addy(n+y, -1);

        }else if (t == 3){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            --x1, --y1, --x2, --y2;
            int xs = sumx(x1, x2);
            int ys = sumy(y1, y2);

            if (x2 - x1 + 1 <= xs
                    and y2 - y1 + 1 <= ys){
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
// for a subrectangle to be completely covered, it has to be completely covered in either x or y direction
// prefix sum-similar; store ranges
// multiset for x and y
