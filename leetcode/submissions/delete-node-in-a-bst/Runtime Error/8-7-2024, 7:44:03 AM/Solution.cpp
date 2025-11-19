// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* find(TreeNode* node, int val) {
        TreeNode* ptr = NULL;
        if (node->left != NULL) {
            if (node->left->val == val) return node;
            TreeNode* res = find(node->left, val);
            if (res != NULL) ptr = res;
        }
        if (node->right != NULL) {
            if (node->right->val == val) return node;
            TreeNode* res = find(node->right, val);
            if (res != NULL) ptr = res;
        }
        
        return ptr;
    }

    void insert(TreeNode* node, TreeNode* in) {
        if (node->val < in->val) {
            if (node->left == NULL) node->left = in;
            else insert(node->left, in);
        } else {
            if (node->right == NULL) node->right = in;
            else insert(node->right, in);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* top = new TreeNode(INT_MAX, root, NULL);
        TreeNode* node = find(top, key);

        if (node == NULL)
            return top->left;

        if (node->left->val == key) {
            auto a = node->left->left;
            auto b = node->left->right;

            node->left = a;
            auto c = a->right;
            a->right = b;
            if (c != NULL)
                insert(b, c);

        } else if (node->right->val == key) {
            auto a = node->right->left;
            auto b = node->right->right;

            node->right = a;
            auto c = a->right;
            a->right = b;
            if (c != NULL)
                insert(b, c);
        }

        return top->left;
    }
};