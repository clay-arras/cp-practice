// https://leetcode.com/problems/delete-nodes-and-return-forest

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        for (int i : to_delete)
            s.insert(i);
        return helper(root, s, true);    
    }
    
    vector<TreeNode*> helper(TreeNode* node, unordered_set<int>& to_delete, bool is_root) {
        if (node == nullptr)
            return {};
        
        vector<TreeNode*> ans;
        if (to_delete.contains(node->val)) {
            auto l = helper(node->left, to_delete, true);
            auto r = helper(node->right, to_delete, true);
            ans.insert(ans.end(), l.begin(), l.end());
            ans.insert(ans.end(), r.begin(), r.end());
            // delete node;
            // node = nullptr;
            node->val = -1;
            return ans;
        }
        
        if (is_root)
            ans.push_back(node);
        auto l = helper(node->left, to_delete, false);
        if (node->left != nullptr && node->left->val == -1) {
            delete node->left;
            node->left = nullptr;
        } 
        
        auto r = helper(node->right, to_delete, false);
        if (node->right != nullptr && node->right->val == -1) {
            delete node->right;
            node->right = nullptr;
        } 
        
        ans.insert(ans.end(), l.begin(), l.end());
        ans.insert(ans.end(), r.begin(), r.end());
        
        return ans;
    }
};