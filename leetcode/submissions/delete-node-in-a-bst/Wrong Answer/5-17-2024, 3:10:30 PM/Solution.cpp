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
    TreeNode* find(TreeNode& n, int val, int l, int r, TreeNode* prev) {
        if (n.val == val) return prev;
        else if (n.val < val && n.right != NULL) return find(*n.right, val, n.val, r, &n);
        else if (n.val > val && n.left != NULL) return find(*n.left, val, l, n.val, &n);
        return NULL;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        TreeNode* prev = new TreeNode(INT_MAX, root, NULL);
        TreeNode* ptr = find(*root, key, -INT_MAX, INT_MAX, prev); 
        root = prev;

        if (ptr != NULL) {
            if (ptr->left != NULL && ptr->left->val == key) {
                TreeNode* tmp = ptr->left->right;
                ptr->left = ptr->left->left;
                ptr = ptr->left;
                while (true) {
                    if (ptr == NULL)
                        break;
                    if (ptr->left == NULL && tmp->val < ptr->val) {
                        ptr->left = tmp;
                        break;
                    }
                    if (ptr->right == NULL && tmp->val > ptr->val) {        
                        ptr->right = tmp;
                        break;
                    }
                    if (tmp->val < ptr->val)
                        ptr = ptr->left;
                    else if (tmp->val > ptr->val)
                        ptr = ptr->right;
                }

            } else if (ptr->right != NULL && ptr->right->val == key) {
                TreeNode* tmp = ptr->right->right;
                ptr->right = ptr->right->left;
                ptr = ptr->right;
                while (true) {
                    if (ptr == NULL)
                        break;
                    if (ptr->left == NULL && tmp->val < ptr->val) {
                        ptr->left = tmp;
                        break;
                    }
                    if (ptr->right == NULL && tmp->val > ptr->val) {
                        ptr->right = tmp;
                        break;
                    }
                    if (tmp->val < ptr->val)
                        ptr = ptr->left;
                    else if (tmp->val > ptr->val)
                        ptr = ptr->right;
                }
            }
        }

        return root->left;
    }
};