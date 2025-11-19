// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    pok = False
    qok = False
    ans = None

    def dfs(self, node, ptarget, qtarget):
        if (node == ptarget):
            Solution.pok = True
        if (node == qtarget):
            Solution.qok = True

        if (node.left != None):
            self.dfs(node.left, ptarget, qtarget)
        if (node.right != None):
            self.dfs(node.right, ptarget, qtarget)
        
        if Solution.pok and Solution.qok and ans is None:
            Solution.ans = node
        

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.dfs(root, p, q)
        return Solution.ans

        