// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};
        
        vector<int> ans;
        queue<TreeNode> q;
        queue<int> d;

        q.push(*root);
        d.push(0);
        while (!q.empty()) {
            TreeNode x = q.front();
            int y = d.front();
            q.pop(), d.pop();

            if (x.right != NULL) {
                q.push(*x.right);
                d.push(y + 1);
            }
            if (x.left != NULL) {
                q.push(*x.left);
                d.push(y + 1);
            }

            if (y >= (int)ans.size()) {
                ans.push_back(x.val);
            }
        }

        return ans;
    }
};