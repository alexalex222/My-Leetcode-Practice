#
# @lc app=leetcode id=116 lang=python3
#
# [116] Populating Next Right Pointers in Each Node
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        self.level_order(root)
        return root
    
    def level_order(self, root):
        if not root:
            return
        
        curr_level = [root]

        while curr_level:
            next_level = []
            for i in range(len(curr_level)):
                node = curr_level[i]
                if i == len(curr_level) - 1:
                    node.next = None
                else:
                    node.next = curr_level[i+1]
                
                if node.left: next_level.append(node.left)
                if node.right: next_level.append(node.right)
            
            curr_level = next_level
        
# @lc code=end

