// https://leetcode.com/problems/valid-square

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int, int>> p;
        p.push_back({p1[0], p1[1]});
        p.push_back({p2[0], p2[1]});
        p.push_back({p3[0], p3[1]});
        p.push_back({p4[0], p4[1]});
        sort(p.begin(), p.end());
        return ();
    }
};