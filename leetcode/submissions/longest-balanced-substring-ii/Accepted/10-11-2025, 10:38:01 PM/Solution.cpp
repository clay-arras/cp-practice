// https://leetcode.com/problems/longest-balanced-substring-ii

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
        // CHANGE: one map per subset k (indices 1..7 used)
        array<unordered_map<tuple<int,int,int>, int, TupleHash>, 8> m;
        for (int k=1; k<8; k++) m[k][make_tuple(0,0,0)] = -1; // base state per subset

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

                int mn = min({(doA ? a : INT_MAX), (doB ? b : INT_MAX), (doC ? c : INT_MAX)});
                auto key = make_tuple(
                    (doA ? a - mn : -a),
                    (doB ? b - mn : -b),
                    (doC ? c - mn : -c)
                );

                auto &mp = m[k];
                auto it = mp.find(key);
                if (it != mp.end()) ans = max(ans, i - it->second);
                else mp[key] = i;
            }
        }
        return ans;
    }
};
