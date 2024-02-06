#
# @lc app=leetcode id=429 lang=python3
#
# [429] N-ary Tree Level Order Traversal
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
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        result = []

        if not root:
            return result
        
        curr_level = [root]
        while curr_level:
            next_level = []
            curr_level_val = []
            for curr_level_node in curr_level:
                curr_level_val.append(curr_level_node.val)
                if curr_level_node.children:
                    for child in curr_level_node.children:
                        next_level.append(child)
            curr_level = next_level
            result.append(curr_level_val)
        
        return result
# @lc code=end

