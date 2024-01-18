#
# @lc app=leetcode id=112 lang=python3
#
# [112] Path Sum
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        self.sum_list = []
        self.dfs(root, 0)
        return targetSum in self.sum_list
    
    def dfs(self, node, path_sum):
        if not node:
            return
        
        path_sum += node.val
        
        if not node.left and not node.right:
            self.sum_list.append(path_sum)
            return
        
        self.dfs(node.right, path_sum)
        self.dfs(node.left, path_sum)

        

        
        

        
# @lc code=end

