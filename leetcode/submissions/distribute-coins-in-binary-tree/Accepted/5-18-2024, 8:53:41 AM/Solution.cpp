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
    map<TreeNode*, int> m;

    int postOrder1(TreeNode* node) {
        int l = 0, r = 0;
        if (node->left != NULL)
            l = postOrder1(node->left);
        if (node->right != NULL)
            r = postOrder1(node->right);
        
        m[node] = node->val + l + r;
        return m[node];
    }

    int postOrder2(TreeNode* node) {
        int l = 0, r = 0;
        if (node->left != NULL)
            l = postOrder2(node->left);
        if (node->right != NULL)
            r = postOrder2(node->right);
        
        int val = 1 + l + r;
        ans += abs(m[node] - val);
        return val;
    }

    int distributeCoins(TreeNode* root) {
        postOrder1(root);
        postOrder2(root);
        return ans;
    }
};