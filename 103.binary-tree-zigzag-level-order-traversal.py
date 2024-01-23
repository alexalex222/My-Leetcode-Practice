#
# @lc app=leetcode id=103 lang=python3
#
# [103] Binary Tree Zigzag Level Order Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.direction = 1
        self.result = []
        self.bfs(root)
        return self.result

    def bfs(self, root):
        if not root:
            return
        
        curr_level = [root]

        while curr_level:
            next_level = []
            curr_level_val = []
            for node in curr_level:
                curr_level_val.append(node.val)
                if node.left: next_level.append(node.left)
                if node.right: next_level.append(node.right)

            if self.direction == 1:
                self.result.append(curr_level_val)
            else:
                l = len(curr_level_val)
                self.result.append(curr_level_val[l::-1])
            
            self.direction = -self.direction
            curr_level = next_level
        
# @lc code=end

