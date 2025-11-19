// https://leetcode.com/problems/longest-balanced-substring-ii

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TupleHash {
        size_t operator()(const std::tuple<int, int, int>& t) const {
            size_t h1 = std::hash<int>{}(std::get<0>(t));
            size_t h2 = std::hash<int>{}(std::get<1>(t));
            size_t h3 = std::hash<int>{}(std::get<2>(t));
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
    
    int longestBalanced(string s) {
        int N = (int)s.size();
        unordered_map<tuple<int, int, int>, int, TupleHash> m;

        // NEW: seed base state so substrings from 0 are counted
        m[make_tuple(0,0,0)] = -1;

        int a = 0, b = 0, c = 0;
        int ans = 0;
        
        for (int i=0; i<N; i++) {
            if (s[i] == 'a') a++;
            if (s[i] == 'b') b++;
            if (s[i] == 'c') c++;

            for (int k=1; k<8; k++) {
                bool doA = (k & 1); 
                bool doB = (k & 2);
                bool doC = (k & 4);

                // CHANGE: use ONE normalization (subtract min) for BOTH lookup and insert
                int mn = min({(doA ? a : INT_MAX), (doB ? b : INT_MAX), (doC ? c : INT_MAX)});
                auto key = make_tuple(
                    (doA ? a - mn : -a),
                    (doB ? b - mn : -b),
                    (doC ? c - mn : -c)
                );

                auto it = m.find(key);
                if (it != m.end()) {
                    // CHANGE: no +1 when base is at -1
                    ans = max(ans, i - it->second);
                }
                if (it == m.end()) {
                    m[key] = i;
                }
            }
        }
        return ans;
    }
};
