#
# @lc app=leetcode id=515 lang=python3
#
# [515] Find Largest Value in Each Tree Row
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []
        self.level_order(root)
        return self.result
    
    def level_order(self, node):
        if not node:
            return
        
        curr_level = []
        curr_level.append(node)

        while curr_level:
            next_level = []
            curr_level_max = float('-inf')

            for n in curr_level:
                curr_level_max = max(curr_level_max, n.val)
                if n.left:
                    next_level.append(n.left)
                
                if n.right:
                    next_level.append(n.right)
            self.result.append(curr_level_max)
            curr_level = next_level

            
        
# @lc code=end

