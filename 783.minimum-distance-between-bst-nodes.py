#
# @lc app=leetcode id=783 lang=python3
#
# [783] Minimum Distance Between BST Nodes
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.prev_val = -1000000
        self.min_dist = 10000000
        self.in_order(root)
        return self.min_dist

    def in_order(self, root):
        if root:
            self.in_order(root.left)

            self.min_dist = min(self.min_dist, root.val - self.prev_val)
            self.prev_val = root.val
                
            
            self.in_order(root.right)

# @lc code=end

