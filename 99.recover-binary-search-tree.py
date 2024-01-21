#
# @lc app=leetcode id=99 lang=python3
#
# [99] Recover Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.first_node = None
        self.second_node = None
        self.prev_node = None
        self.inOder(root)
        if self.first_node is not None:
            temp = self.first_node.val
            self.first_node.val = self.second_node.val
            self.second_node.val = temp

    def inOder(self, node):
        if node:
            self.inOder(node.left)

            if self.first_node is None and (self.prev_node is None or self.prev_node.val >= node.val):
                self.first_node = self.prev_node
            
            if self.first_node is not None and (self.prev_node.val >= node.val):
                self.second_node = node 

            self.prev_node = node

            self.inOder(node.right)
        
# @lc code=end

