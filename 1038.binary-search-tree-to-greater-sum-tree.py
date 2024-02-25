#
# @lc app=leetcode id=1038 lang=python3
#
# [1038] Binary Search Tree to Greater Sum Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.cumsum = 0
        self.in_order(root)
        return root

    def in_order(self, node):
        if node:
            self.in_order(node.right)
            self.cumsum += node.val
            node.val = self.cumsum
            self.in_order(node.left)
        
# @lc code=end

