// https://leetcode.com/problems/path-sum-iii

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
    int ans = 0;
    int t;
    map<int, int> m;

    void dfs(TreeNode n, int cur) {
        cur += n.val;
        m[n.val - cur]++;
        ans += m[t - cur];

        if (n.left != NULL) 
            dfs(*n.left, cur);
        if (n.right != NULL) 
            dfs(*n.right, cur);
        
        m[n.val - cur]--;
        cur -= n.val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        t = targetSum;

        if (root == NULL)
            return 0;
       
        dfs(*root, 0);
        return ans;
    }
};