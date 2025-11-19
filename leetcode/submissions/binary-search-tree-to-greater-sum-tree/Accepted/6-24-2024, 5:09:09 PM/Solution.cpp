// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    int trav(TreeNode* node, int sum) {
        if (node->right != NULL)
            sum = trav(node->right, sum);
        sum += node->val;
        node->val = sum;
        if (node->left != NULL)
            sum = trav(node->left, sum);
        return sum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        trav(root, 0);
        return root;
    }
};