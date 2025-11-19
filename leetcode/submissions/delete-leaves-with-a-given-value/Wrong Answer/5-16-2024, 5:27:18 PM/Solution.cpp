// https://leetcode.com/problems/delete-leaves-with-a-given-value

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if (root->left != NULL) {
            removeLeafNodes(root->left, target);
            if (root->left->left == NULL && root->left->right == NULL &&
                root->left->val == target) 
                    root->left = NULL;
        }
        if (root->right != NULL) {
            removeLeafNodes(root->right, target);
            if (root->right->left == NULL && root->right->right == NULL &&
                root->right->val == target) 
                    root->right = NULL;
        }

        return root;
    }
};