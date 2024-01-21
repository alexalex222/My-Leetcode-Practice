#
# @lc app=leetcode id=144 lang=python3
#
# [144] Binary Tree Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.preOrder(root, result)
        return result
    
    def preOrder(self, node, node_list):
        if node:
            node_list.append(node.val)
            self.preOrder(node.left, node_list)
            self.preOrder(node.right, node_list)
        
# @lc code=end

