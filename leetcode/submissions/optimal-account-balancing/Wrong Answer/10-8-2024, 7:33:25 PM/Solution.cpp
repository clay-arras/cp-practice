// https://leetcode.com/problems/optimal-account-balancing

class Solution {
public:
    const int MX = 11;
    // vector<pair<int, int>> adj_list[MX];
    // int amount[MX];
    // bool visited[MX];

    // void dfs(int x) {

    // }

    int minTransfers(vector<vector<int>>& transactions) {
        // for (auto i : transactions) {
        //     adj_list[i[0]].push_back({i[1], i[2]});
        // }
        vector<int> amount(MX, 0);
        for (auto i : transactions) {
            amount[i[0]] -= i[2];
            amount[i[1]] += i[2];
        }
        for (int i : amount)
            cout << i << " ";
        cout << endl;

        int ans;
        sort(amount.begin(), amount.end());
        for (ans = 0; amount[0] != 0; ans++) {
            int N = (int)amount.size();
            amount.push_back(amount[0] + amount[N-1]);
            amount[0] = 0;
            amount[N-1] = 0;
            sort(amount.begin(), amount.end());
        }

        return ans;
    }
};

// positive means is owed money
// negative means needs to give money
// [-2, 1, 1]
// [0, 1, 5, -6, -2, 2]
// [4, -1, -1, -1, -1]

// [-1, -1, -1, -1, 4] = 4
// [-6, -2, 0, 1, 2, 5] = 3

// 1 [-10, -7, -5, -2, 0, 1, 1, 1, 6, 7, 8]
// 2 [-7, -5, -2, -2, 0, 1, 1, 1, 6, 7]
// 3 [-5, -2, -2, 0, 1, 1, 1, 6]
// 4 [-2, -2, 0, 1, 1, 1, 1]
// 5 [-2, -1, 0, 1, 1, 1]
// 6 [-1, -1, 0, 1, 1]
// 7 [-1, 0, 1]
// 8 [0, 0, 0]

// [12, 5, -2, -5, -8]
// [-7, -5, -3, 5, 10] = 3
// [-5, -3, 3, 5] = 2

// lower bound solution -> max(# pos, # neg)
// two pointers