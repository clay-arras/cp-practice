// https://leetcode.com/problems/path-sum

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
    int t;
    
    bool dfs(TreeNode n, int sum) {
        sum += n.val;
        if (n.left == NULL && n.right == NULL)
            return (sum == t);

        bool ret = false;
        if (n.left != NULL)
            ret |= dfs(*n.left, sum);
        if (n.right != NULL)
            ret |= dfs(*n.right, sum);
        return ret;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        if (root == NULL)
            return false;
        return dfs(*root, 0);
    }
};