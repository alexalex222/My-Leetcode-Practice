#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        self.result = None
        self.inOder(root, [])
        return self.result

    def inOder(self, node, node_list):
        if node:
            self.inOder(node.left, node_list)
            node_list.append(node.val)
            if len(node_list) == self.k:
                self.result = node_list[-1]
                return
            self.inOder(node.right, node_list)
        
# @lc code=end

