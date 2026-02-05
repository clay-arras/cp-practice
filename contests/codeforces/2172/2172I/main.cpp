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

vector<int> hullInd(const vector<pair<T, T> >& v) {
    int ind = (int)(min_element(v.begin(), v.end()) - v.begin());
    vector<int> cand, C{ind}; 

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
    ld x1, x2, y1, y2;
    if (fabsl(a.first - b.first) < 1e-15L) {
        ld x = a.first;
        y1 = sqrt(- sq(x) + sq((long long)R));
        y2 = -sqrt(- sq(x) + sq((long long)R));

        x1 = x, x2 = x;
    } else {
        ld m = (ld)(a.second - b.second) / (ld)(a.first - b.first);
        ld bp = a.second - m * a.first;

        x1 = - ( (ld)sqrt( (sq(m) + 1)*sq((ld)R) - sq(bp) ) + bp*m) / (sq(m) + 1);
        x2 = ( (ld)sqrt( (sq(m) + 1)*sq((ld)R) - sq(bp) ) - bp*m) / (sq(m) + 1);

        y1 = m * x1 + bp;
        y2 = m * x2 + bp;
    }

    ld midx = (x1 + x2) / 2.0;
    ld midy = (y1 + y2) / 2.0;

    pair<ld, ld> pt1 = {x1, y1};
    pair<ld, ld> pt2 = {x2, y2};
    ld h = dist({midx, midy});
    ld bs = sqrt(sq(pt1.first - pt2.first) + sq(pt1.second - pt2.second));
    
    ld tri = h*bs/2.0;

    ld rad = acos((pt1.first*pt2.first + pt1.second*pt2.second) / (dist(pt1)*dist(pt2)));

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
    ans = max(ans, calc_segment(points[hull.back()], points[hull[0]]));

    int hs = hull.size();
    for (int i=0; i<hs; i++) {
        auto& V = points[hull[i]];
        bool allSameSide = true;
        int sign = 0;
        for (int j = 0; j < hs && allSameSide; j++) {
            if (j == i) continue;
            auto& P = points[hull[j]];
            T cr = V.second * P.first - V.first * P.second;
            if (cr == 0) continue;
            if (sign == 0) sign = (cr > 0) ? 1 : -1;
            else if ((cr > 0 ? 1 : -1) != sign) allSameSide = false;
        }
        if (allSameSide) {
            ld halfCircle = acosl(-1.0L) * sq((ld)R) / 2.0;
            ans = max(ans, halfCircle);
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
}
