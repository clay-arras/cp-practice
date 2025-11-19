// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int count = 0;
    void dfs(TreeNode n, int maxVal) {
        count += (int)(n.val >= maxVal); 
        maxVal = max(maxVal, n.val);
        if (n.left != NULL)
            dfs(*n.left, maxVal);
        if (n.right != NULL)
            dfs(*n.right, maxVal);
    }

    int goodNodes(TreeNode* root) {
       count = 0;
       dfs(*root, -INT_MAX);
       return count; 
    }
};