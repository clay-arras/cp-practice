// https://leetcode.com/problems/ipo

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        multiset<pair<int, int>> s;
        int N = (int)profits.size();

        for (int i=0; i<N; i++)
            s.insert({-capital[i], -profits[i]});

        int ans = w;
        for (int i=0; i<k; i++) {
            auto it = s.lower_bound({-ans, -INT_MAX});
            if (it != s.end()) {
                ans += -it->second;
                s.erase(it);
            }
        }

        return ans;
    }
};