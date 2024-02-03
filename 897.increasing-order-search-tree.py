#
# @lc app=leetcode id=897 lang=python3
#
# [897] Increasing Order Search Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        self.result = TreeNode(0)
        self.ptr = self.result
        self.in_order(root)
        return self.result.right

    def in_order(self, root):
        if root:
            self.in_order(root.left)
            self.ptr.right = TreeNode(root.val)
            self.ptr = self.ptr.right
            self.in_order(root.right)
        
        
# @lc code=end

