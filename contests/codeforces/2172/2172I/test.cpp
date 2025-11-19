#include <bits/stdc++.h>
using namespace std;


using T = long long;


T sq(T a) { return a * a; }
pair<T, T> operator-(const pair<T, T> &l, const pair<T, T> &r) { 
    return pair<T, T>(l.first - r.first, l.second - r.second); 
}
T cross(const pair<T, T> &a, const pair<T, T> &b) { 
    return a.first * b.second - a.second * b.first; 
}
T cross(const pair<T, T> &p, const pair<T, T> &a, const pair<T, T> &b) {
    return cross(a - p, b - p);
}
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
