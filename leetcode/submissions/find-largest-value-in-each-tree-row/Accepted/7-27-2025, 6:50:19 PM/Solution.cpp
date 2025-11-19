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
    vector<int> ans;
    vector<int> largestValues(TreeNode* root) {
        rec(root, 0);
        return ans;
    }
    
    void rec(TreeNode* node, int depth) {
        if (node == nullptr)
            return;
        if (depth >= (int)ans.size()) {
            ans.push_back(node->val);
        }
        ans[depth] = max(ans[depth], node->val);
        
        rec(node->left, depth+1);
        rec(node->right, depth+1);
    }
};