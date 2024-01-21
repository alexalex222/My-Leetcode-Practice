#
# @lc app=leetcode id=257 lang=python3
#
# [257] Binary Tree Paths
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.result = []
        if not root:
            return self.result
        else:
            self.dfs(root, None)
        return self.result
    
    def dfs(self, node, curr_path):
        if not node:
            return
        
        if curr_path is None:
            curr_path = str(node.val)
        else:
            curr_path += '->' + str(node.val)

        if not node.left and not node.right:
            self.result.append(curr_path)
            return

        self.dfs(node.left, curr_path)
        self.dfs(node.right, curr_path)

        
# @lc code=end

