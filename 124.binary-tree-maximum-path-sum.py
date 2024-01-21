#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.result = float('-inf')
        self.max_gain(root)
        return self.result

    def max_gain(self, root):
        if not root:
            return 0
        
        gain_left = max(self.max_gain(root.left), 0)
        gain_right = max(self.max_gain(root.right), 0)

        curr_root_max = root.val + gain_right + gain_left
        self.result = max(self.result, curr_root_max)

        return root.val + max(gain_left, gain_right)

# @lc code=end

