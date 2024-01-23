#
# @lc app=leetcode id=111 lang=python3
#
# [111] Minimum Depth of Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        self.depth = 0
        self.bfs(root)
        return self.depth
    
    def bfs(self, root):
        if not root:
            return
        
        curr_level = [root]
        self.depth += 1

        while curr_level:
            next_level = []
            for node in curr_level:
                if node.left: next_level.append(node.left)
                if node.right: next_level.append(node.right)
                if not node.left and not node.right: return
            
            curr_level = next_level
            self.depth += 1
        
# @lc code=end

