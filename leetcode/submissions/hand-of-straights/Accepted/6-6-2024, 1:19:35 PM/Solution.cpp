// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((int)hand.size() % groupSize) return false;

        unordered_multiset<int> s;
        for (auto i : hand)
            s.insert(i);

        sort(hand.begin(), hand.end());
        bool ans = true;
        int N = (int)hand.size(); 
        for (int i=0; i<N; i++) {
            if (!s.count(hand[i] - 1) && s.count(hand[i])) {
                for (int j=0; j<groupSize; j++) {
                    auto val = s.find(hand[i] + j);
                    ans &= (val != s.end());
                    if (val != s.end())
                        s.erase(val);
                }
            }
        }
        return ans;
    }
};