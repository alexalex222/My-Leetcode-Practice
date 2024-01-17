#
# @lc app=leetcode id=1022 lang=python3
#
# [1022] Sum of Root To Leaf Binary Numbers
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        self.sum = 0
        self.dfs(root, 0)
        return self.sum
    
    def dfs(self, root, path_sum):
        if not root:
            return
        
        path_sum = path_sum * 2 + root.val

        if not root.left and not root.right:
            self.sum = self.sum + path_sum
            return
        
        self.dfs(root.left, path_sum)
        self.dfs(root.right, path_sum)

        
# @lc code=end

