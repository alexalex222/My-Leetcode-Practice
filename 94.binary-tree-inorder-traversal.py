#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.inOrder(root, result)
        return result
    
    def inOrder(self, node, node_list):
        if node:
            self.inOrder(node.left, node_list)
            node_list.append(node.val)
            self.inOrder(node.right, node_list)
        
# @lc code=end

