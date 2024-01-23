#
# @lc app=leetcode id=107 lang=python3
#
# [107] Binary Tree Level Order Traversal II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.result = []
        self.bfs(root)
        l = len(self.result)
        return self.result[l-1::-1]
    
    def bfs(self, root):
        if not root:
            return
        
        curr_level = [root]
        
        while curr_level:
            next_level = []
            curr_level_val = []
            for node in curr_level:
                curr_level_val.append(node.val)
                if node.left: next_level.append(node.left)
                if node.right: next_level.append(node.right)

            self.result.append(curr_level_val)
            curr_level = next_level
        
# @lc code=end

