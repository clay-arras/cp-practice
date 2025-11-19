// https://leetcode.com/problems/search-in-a-binary-search-tree

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
    TreeNode* find(TreeNode& n, int val, int l, int r) {
        if (n.val == val)
            return &n;
        else if (n.val > val && n.left != NULL) 
            return find(*n.left, val, l, n.val);
        else if (n.val < val && n.right != NULL)
            return find(*n.right, val, n.val, r);
        return NULL;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return find(*root, val, -INT_MAX, INT_MAX);
    }
};