// https://leetcode.com/problems/distribute-coins-in-binary-tree

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

    int postOrder(TreeNode* node) {
        int l = 0, r = 0;
        if (node->left != NULL)
            l = postOrder(node->left);
        if (node->right != NULL)
            r = postOrder(node->right);
        
        int val = l + r - 1 + node->val;
        ans += abs(l) + abs(r);
        return val;
    }

    int distributeCoins(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};