// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> ret;
    vector<int> largestValues(TreeNode* root) {
        search(root, 0);
        return ret;
    }

    void search(TreeNode* node, int dept) {
        if (node == NULL)
            return;
        if ((int)ret.size() < dept+1)
            ret.push_back(node->val);
        else ret[dept] = max(ret[dept], node->val);

        if (node->left != NULL)
            search(node->left, dept+1);
        if (node->right != NULL)
            search(node->right, dept+1);
    }
};