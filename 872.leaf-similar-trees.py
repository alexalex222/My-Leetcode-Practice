#
# @lc app=leetcode id=872 lang=python3
#
# [872] Leaf-Similar Trees
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leaf_1 = []
        leaf_2 = []
        self.dfs(root1, leaf_1)
        self.dfs(root2, leaf_2)
        return leaf_1 == leaf_2
    
    def dfs(self, root, leaf):
        if not root:
            return
        
        if not root.left and not root.right:
            leaf.append(root.val)
            return
        
        self.dfs(root.left, leaf)
        self.dfs(root.right, leaf)
        
# @lc code=end

