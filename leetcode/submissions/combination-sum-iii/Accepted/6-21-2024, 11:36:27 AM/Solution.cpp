// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>> ans;
    int K, N;
    void backtrack(vector<int> a, int i) {
        int sum = 0;
        for (auto i : a)
            sum += i;

        if ((int)a.size() == K && sum == N) {
            ans.push_back(a);
            return;
        }
        else if ((int)a.size() > K || sum > N || i > 9) {
            return;
        }

        backtrack(a, i+1);
        a.push_back(i);
        backtrack(a, i+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        K = k, N = n;
        backtrack({}, 1); 
        return ans;
    }
};