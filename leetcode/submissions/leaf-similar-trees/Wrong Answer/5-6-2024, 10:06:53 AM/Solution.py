// https://leetcode.com/problems/leaf-similar-trees

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    leaves1 = []
    leaves2 = []

    def dfs1(self, root):
        if root is None:
            return
        if root.left is None and root.right is None:
            Solution.leaves1.append(root.val)
        self.dfs1(root.left)
        self.dfs1(root.right)

    def dfs2(self, root):
        if root is None:
            return
        if root.left is None and root.right is None:
            Solution.leaves2.append(root.val)
        self.dfs2(root.left)
        self.dfs2(root.right)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.dfs1(root1)
        self.dfs2(root2)
        return Solution.leaves1 == Solution.leaves2