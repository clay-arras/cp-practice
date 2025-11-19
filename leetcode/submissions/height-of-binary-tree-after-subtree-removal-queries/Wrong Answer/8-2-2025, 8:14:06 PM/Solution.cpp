// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries

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
    const static int MX = 1e5+5;
    int memo[MX];
    int depth[MX];

    void dp(TreeNode* node, int height) {
        if (node == nullptr) 
            return;

        if (node->left) {
            memo[node->left->val-1] = memo[node->val-1];
            if (node->right) 
                memo[node->left->val-1] = 
                    max(memo[node->left->val-1], depth[node->right->val-1] + height);
        }

        if (node->right) {
            memo[node->right->val-1] = memo[node->val-1];
            if (node->left) 
                memo[node->right->val-1] = 
                    max(memo[node->right->val-1], depth[node->left->val-1] + height);
        }

        dp(node->left, height+1);
        dp(node->right, height+1);
    }

    int dfs(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr)
            return depth[node->val - 1] = 0;
        
        if (node->left != nullptr)
            depth[node->val - 1] = max(depth[node->val - 1], dfs(node->left) + 1);
        if (node->right != nullptr)
            depth[node->val - 1] = max(depth[node->val - 1], dfs(node->right) + 1);
        return depth[node->val - 1];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);

        memo[root->val - 1] = 0;
        dp(root, 1);

        for (int i=0; i<(int)queries.size(); i++) {
            queries[i] = memo[queries[i]-1];
        }
        
        return queries;
    }
};