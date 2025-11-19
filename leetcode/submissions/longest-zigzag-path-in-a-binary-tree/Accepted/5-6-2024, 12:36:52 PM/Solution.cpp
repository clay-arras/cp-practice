// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

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
    int ans = 0;

    // prev is whether the last one was left
    void dfs(TreeNode n, int val, bool prev) {
        ans = max(ans, val);

        if (n.left != NULL) {
            if (prev) {
                dfs(*n.left, 1, true);
            } else {
                dfs(*n.left, val + 1, true);
            }
        }
        if (n.right != NULL) {
            if (prev) {
                dfs(*n.right, val + 1, false);
            } else {
                dfs(*n.right, 1, false);
            }
        }
    }

    int longestZigZag(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left != NULL)
            dfs(*(root->left), 1, true);
        if (root->right != NULL)
            dfs(*(root->right), 1, false);
        return ans;
    }
};