// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
public:
    TreeNode* lastNodeInChain;

    void dfs(TreeNode* node, TreeNode* prev, bool isPrevLeftChild) {
        if (node == nullptr)
            return;

        if (prev != nullptr) {
            assert(lastNodeInChain->left == nullptr || lastNodeInChain->left == node);
            lastNodeInChain->left = node;
            if (lastNodeInChain != prev) {
                if (isPrevLeftChild) 
                    prev->left = nullptr;
                else prev->right = nullptr;
            }
        }
        lastNodeInChain = node;

        dfs(node->left, node, true);
        dfs(node->right, node, false);
        node->right = nullptr;
    }
    void flip(TreeNode* node) {
        if (node == nullptr)
            return;
        swap(node->left, node->right);

        flip(node->left);
        flip(node->right);
    }

    void flatten(TreeNode* root) {
        lastNodeInChain = nullptr;
        dfs(root, nullptr, false);
        lastNodeInChain = nullptr;
        flip(root);
    }
};