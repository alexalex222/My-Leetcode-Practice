#
# @lc app=leetcode id=938 lang=python3
#
# [938] Range Sum of BST
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.low = low
        self.high = high
        self.result = 0
        self.in_order(root)
        return self.result
    
    def in_order(self, node):
        if node:
            self.in_order(node.left)
            if self.low <= node.val <= self.high:
                self.result += node.val
            elif node.val > self.high:
                return
            self.in_order(node.right)
        
# @lc code=end

