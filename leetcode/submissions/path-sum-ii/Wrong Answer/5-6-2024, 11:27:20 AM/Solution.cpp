// https://leetcode.com/problems/path-sum-ii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    int t;

    bool dfs(TreeNode n, int sum) {
        sum += n.val;
        if (n.left == NULL && n.right == NULL) {
            if (sum == t) {
                ans.push_back({n.val});
                return true;
            } else {
                return false;
            }
        }

        bool ltree = false, rtree = false;
        if (n.left != NULL) {
            ltree = dfs(*n.left, sum);
            if (ltree) {
                int len = (int)ans.size();
                ans[len - 1].push_back(n.val);
            }
        }
        if (n.right != NULL) {
            rtree = dfs(*n.right, sum);
            if (rtree) {
                int len = (int)ans.size();
                ans[len - 1].push_back(n.val);
            }
        }

        return (ltree || rtree);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        if (root == NULL)
            return {{}};
        dfs(*root, 0);
        for (auto &i : ans)
            reverse(i.begin(), i.end());
        return ans;
    }
};