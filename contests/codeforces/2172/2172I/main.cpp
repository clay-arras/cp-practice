#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

using T = long long;

T sq(T a) { return a * a; }
pair<T, T> operator-(const pair<T, T> &l, const pair<T, T> &r) { 
    return pair<T, T>(l.first - r.first, l.second - r.second); }
T cross(const pair<T, T> &a, const pair<T, T> &b) { 
    return a.first * b.second - a.second * b.first; }
T cross(const pair<T, T> &p, const pair<T, T> &a, const pair<T, T> &b) {
    return cross(a - p, b - p); }
T abs2(const pair<T, T>& p) { return sq(p.first)+sq(p.second); }

vector<T> hullInd(const vector<pair<T, T> >& v) {
    int ind = (int)(min_element(v.begin(), v.end()) - v.begin());
    vector<T> cand, C{ind}; 

    for (int i=0; i<(int)v.size(); ++i) 
        if (v[i] != v[ind]) 
            cand.push_back(i);

    sort(cand.begin(), cand.end(),[&](int a, int b) {
            pair<T, T> x = v[a]-v[ind], y = v[b]-v[ind]; 
            T t = cross(x,y);
            return t != 0 ? t > 0 : abs2(x) < abs2(y); 
        });
    for (auto& c: cand) {
        while ((int)C.size() > 1 && cross(v[end(C)[-2]],v[C.back()],v[c]) <= 0)
            C.pop_back();
        C.push_back(c); 
    }
    return C;
}

typedef long double ld;
ld sq(ld a) { return a * a; }

ld dist(const pair<ld, ld>& a) {
    return sqrt(sq(a.first) + sq(a.second));
}

int R;
ld calc_segment(pair<T, T> a, pair<T, T> b) {
    // part a

    ld x1, x2, y1, y2;
    if (fabsl(a.first - b.first) < 1e-15L) {
        ld x = a.first;
        y1 = sqrt(- sq(x) + sq((long long)R));
        y2 = -sqrt(- sq(x) + sq((long long)R));

        x1 = x, x2 = x;
    } else {
        ld m = (ld)(a.second - b.second) / (ld)(a.first - b.first);
        ld bp = a.second - m * a.first;

        // part b
        x1 = - ( (ld)sqrt( (sq(m) + 1)*sq((ld)R) - sq(bp) ) + bp*m) / (sq(m) + 1);
        x2 = ( (ld)sqrt( (sq(m) + 1)*sq((ld)R) - sq(bp) ) - bp*m) / (sq(m) + 1);

        y1 = m * x1 + bp;
        y2 = m * x2 + bp;
    }

    // part c
    ld midx = (x1 + x2) / 2.0;
    ld midy = (y1 + y2) / 2.0;

    pair<ld, ld> pt1 = {x1, y1};
    pair<ld, ld> pt2 = {x2, y2};
    ld h = dist({midx, midy});
    ld bs = dist(pt1 - pt2);
    
    ld tri = h*bs/2.0;

    // part d
    ld rad = acos((pt1.first*pt2.first + pt1.second*pt2.second) / (dist(pt1)*dist(pt2)));

    // part e
    ld sec = (rad / 2.0) * sq((ld)R);
    ld area = sec - tri;

    return area;
}

void solve() {
    int N; cin >> N >> R;

    vector<pair<T, T>> points;
    for (int i=0; i<N; i++) {
        long long x, y; cin >> x >> y;
        points.push_back({x, y});
    }

    auto hull = hullInd(points);
    long double ans = 0;

    for (int i=0; i<(int)hull.size()-1; i++) 
        ans = max(ans, calc_segment(points[hull[i]], points[hull[i+1]]));
    ans = max(ans, calc_segment(points[hull[0]], points[hull[N-1]]));

    cout << fixed << setprecision(12) << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
