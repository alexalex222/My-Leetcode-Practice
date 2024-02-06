#
# @lc app=leetcode id=589 lang=python3
#
# [589] N-ary Tree Preorder Traversal
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        self.result = []
        self.pre_order(root)
        return self.result
    
    def pre_order(self, node):
        if not node:
            return
        
        self.result.append(node.val)
        if node.children:
            for child in node.children:
                self.pre_order(child)
        
# @lc code=end

