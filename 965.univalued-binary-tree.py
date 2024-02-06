#
# @lc app=leetcode id=965 lang=python3
#
# [965] Univalued Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        self.first_val = None
        self.result = True
        self.in_order(root)
        return self.result

    def in_order(self, node):
        if not node: return 

        self.in_order(node.left)
        if self.first_val is None: 
            self.first_val = node.val
        else: 
            if node.val != self.first_val:
                self.result = False
        self.in_order(node.right)
        
# @lc code=end

