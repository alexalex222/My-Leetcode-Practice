#
# @lc app=leetcode id=199 lang=python3
#
# [199] Binary Tree Right Side View
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []
        self.bfs(root)
        return self.result
    
    def bfs(self, root):
        if not root:
            return
        
        curr_level = [root]
        while curr_level:
            curr_level_val = []
            next_level = []

            for node in curr_level:
                curr_level_val.append(node.val)
                if node.left: next_level.append(node.left)
                if node.right: next_level.append(node.right)
            
            self.result.append(curr_level_val[-1])
            curr_level = next_level
        
# @lc code=end

