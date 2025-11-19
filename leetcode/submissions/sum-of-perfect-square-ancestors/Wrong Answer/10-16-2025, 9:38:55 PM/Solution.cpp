// https://leetcode.com/problems/sum-of-perfect-square-ancestors

class Solution {
public:
    const static int MX = 1e5+7;
    vector<int> adj_list[MX];
    vector<bool> visited;
    multiset<set<int>> hash;
    vector<set<int>> factors;

    long long ans = 0;
    void dfs(int x) {
        visited[x] = true;
        ans += hash.count(factors[x]);
        hash.insert(factors[x]);

        for (int i : adj_list[x]) {
            if (!visited[i])
                dfs(i);
        }
        hash.erase(hash.find(factors[x]));
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        int mx = *max_element(nums.begin(), nums.end());
        for (int i : nums) {
            set<int> odds;
            for (int f=2; f<=sqrt(i) + 1; f++) {
                int cnt = 0;
                for (; i%f == 0; cnt++) 
                    i /= f;
                if (cnt % 2) odds.insert(f);
            }
            factors.push_back(odds);
        }
        visited = vector<bool>(n, 0);
        dfs(0);

        return ans;
    }
};