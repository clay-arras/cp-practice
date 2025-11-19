// https://leetcode.com/problems/diameter-of-binary-tree

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
    int rec(TreeNode* node) {
        if (node == nullptr) return -1;
        int l = 1 + rec(node->left);
        int r = 1 + rec(node->right);
        
        ans = max(ans, l+r);
        return max(l, r);
    } 
    
    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return ans;
    }
};