// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((int)hand.size() % groupSize) return false;

        map<int, int> m;
        for (auto i : hand)
            m[i]++;

        for (auto [k, v] : m) {
            if (v > 0)
                for (int i=0; i<v; i++) 
                    for (int j=k; j<k+groupSize; j++)
                        m[j]--;
        }
        bool ans = true;
        for (auto [k, v] : m)
            ans &= (v >= 0);

        return ans;
    }
};