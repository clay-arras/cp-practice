// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    ans = None

    def dfs(self, node, ptarget, qtarget):
        pok = False
        qok = False
        if (node == ptarget):
            pok = True
        if (node == qtarget):
            qok = True

        a, b, c, d = [False] * 4
        if (node.left != None):
            a, b = self.dfs(node.left, ptarget, qtarget)
        if (node.right != None):
            c, d = self.dfs(node.right, ptarget, qtarget)
        
        pok |= a or c
        qok |= b or d
        if pok and qok and Solution.ans is None:
            Solution.ans = node
        
        return pok, qok
        

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        Solution.ans = None
        self.dfs(root, p, q)
        return Solution.ans

        