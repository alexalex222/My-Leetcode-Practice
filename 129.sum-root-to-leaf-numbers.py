#
# @lc app=leetcode id=129 lang=python3
#
# [129] Sum Root to Leaf Numbers
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.tot_sum = 0
        self.dfs(root, 0)
        return self.tot_sum
    
    def dfs(self, node, curr_sum):
        if not node:
            return
        
        curr_sum = curr_sum * 10 + node.val

        if not node.left and not node.right:
            self.tot_sum += curr_sum
            return
        
        self.dfs(node.left, curr_sum)
        self.dfs(node.right, curr_sum)
        
# @lc code=end

