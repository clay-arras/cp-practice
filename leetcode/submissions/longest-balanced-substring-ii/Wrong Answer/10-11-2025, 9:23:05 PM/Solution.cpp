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
        unordered_map<tuple<int, int, int>, int, TupleHash> m;

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

                int mx = max({(doA ? a : 0), (doB ? b : 0), (doC ? c : 0)});
                if (m.count({(doA ? mx-a : -a), (doB ? mx-b : -b), (doC ? mx-c : -c)})) {
                    ans = max(ans, i - m[{(doA ? mx-a : -a), (doB ? mx-b : -b), (doC ? mx-c : -c)}] + 1);
                }
                int mn = min({(doA ? a : INT_MAX), (doB ? b : INT_MAX), (doC ? c : INT_MAX)});
                if (!m.count({(doA ? a-mn : -a), (doB ? b-mn : -b), (doC ? c-mn : -c)}))
                    m[{(doA ? a-mn : -a), (doB ? b-mn : -b), (doC ? c-mn : -c)}] = i; 
            }
        }

        // for (auto [k, v] : m) {
        //     cout << setw(4) << get<0>(k) << " " << setw(4) << get<1>(k) << " " << setw(4) << get<2>(k) << ": " << v << endl;
        // }
        return ans;
    }
};