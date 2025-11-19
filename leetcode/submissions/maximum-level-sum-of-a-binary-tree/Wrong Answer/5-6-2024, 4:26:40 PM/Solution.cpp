// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode> q;
        queue<int> d;
        vector<int> sum;

        q.push(*root);
        d.push(0);
        while (!q.empty()) {
            TreeNode x = q.front();
            int y = d.front();
            q.pop(), d.pop();

            if (x.left != NULL) {
                q.push(*x.left);
                d.push(y + 1);
            }
            if (x.right != NULL) {
                q.push(*x.right);
                d.push(y + 1);
            }

            if (y >= (int)sum.size()) 
                sum.push_back(0);
            sum[y] += x.val;
        }

        int ans = 0, maxSum = 0;
        for (int i=0; i<(int)sum.size(); i++) {
            if (sum[i] > maxSum) {
                ans = i + 1;
                maxSum = sum[i];
            }
        }
        return ans;
    }
};