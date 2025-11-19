// https://leetcode.com/problems/optimal-account-balancing

class Solution {
public:
    const int MX = 11;

    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> amount(MX, 0);
        for (auto i : transactions) {
            amount[i[0]] -= i[2];
            amount[i[1]] += i[2];
        }
        sort(amount.begin(), amount.end());
        
        int ans;
        for (; amount[0] != 0; ans++) {
            int N = (int)amount.size();
            amount.push_back(amount[0] + amount[N-1]);
            amount[0] = 0;
            amount[N-1] = 0;
            sort(amount.begin(), amount.end());
        }

        return min(ans, max(temp1, temp2));
    }
};
