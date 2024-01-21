#
# @lc app=leetcode id=513 lang=python3
#
# [513] Find Bottom Left Tree Value
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.result = []
        self.level_order(root)
        return self.result[-1]
    
    def level_order(self, node):
        if not node:
            return
        
        curr_level = []
        curr_level.append(node)

        while(curr_level):
            next_level = []
            for i in range(len(curr_level)):
                n = curr_level[i]
                if i == 0:
                    self.result.append(n.val)
                if n.left: next_level.append(n.left)
                if n.right: next_level.append(n.right)
            curr_level = next_level

        
# @lc code=end

