// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<int> g;
        for (auto gift : gifts)
            g.insert(gift);

        for (int i=0; i<k; i++) {
            auto it = g.end(), --it;
            g.insert(floor(sqrt(*it)));
            g.erase(it);
        }
        long long ans = 0;
        for (auto it : g)
            ans += it;
        return ans;
    }
};