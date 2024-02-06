#
# @lc app=leetcode id=590 lang=python3
#
# [590] N-ary Tree Postorder Traversal
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
    def postorder(self, root: 'Node') -> List[int]:
        self.result = []
        self.post_order(root)
        return self.result
    
    def post_order(self, node):
        if not node:
            return
        
        if node.children:
            for child in node.children:
                self.post_order(child)
        self.result.append(node.val)
        
# @lc code=end

