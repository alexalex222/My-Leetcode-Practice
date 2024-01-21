#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.is_valid = True
        self.inOder(root, [])
        return self.is_valid
    
    def inOder(self, node, node_list):
        if node:
            self.inOder(node.left, node_list)
            if len(node_list) > 0 and node_list[-1] >= node.val:
                self.is_valid = False
                return
            else:
                node_list.append(node.val)
            self.inOder(node.right, node_list)
        
# @lc code=end

