#
# @lc app=leetcode id=971 lang=python3
#
# [971] Flip Binary Tree To Match Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: List[int]) -> List[int]:
        self.i = 0
        self.result = []
        if self.dfs(root, voyage):
            return self.result
        else:
            return [-1]
    
    def dfs(self, node, v):
        if not node:
            return True
        
        if node.val != v[self.i]:
            return False
        
        self.i = self.i + 1

        if node.left and node.left.val != v[self.i]:
            if node.right and node.right.val == v[self.i]:
                self.result.append(node.val)
                node.left, node.right = node.right, node.left
            else:
                return False
            
        return self.dfs(node.left, v) and self.dfs(node.right, v)
        

# @lc code=end

