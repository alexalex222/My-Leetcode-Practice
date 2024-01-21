#
# @lc app=leetcode id=145 lang=python3
#
# [145] Binary Tree Postorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.postOrder(root, result)
        return result

    def postOrder(self, node, node_list):
        if node:
            self.postOrder(node.left, node_list)
            self.postOrder(node.right, node_list)
            node_list.append(node.val)
        
# @lc code=end

