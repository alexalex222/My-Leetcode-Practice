#
# @lc app=leetcode id=113 lang=python3
#
# [113] Path Sum II
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.result = []
        self.dfs(root, targetSum, [])
        return self.result

    def dfs(self, node, target, curr_path):
        if not node:
            return
        
        curr_path.append(node.val)

        if not node.left and not node.right and target == node.val:
            self.result.append(curr_path.copy())
            #return


        self.dfs(node.left, target - node.val, curr_path)
        self.dfs(node.right, target - node.val, curr_path)

        curr_path.pop()
            
        
# @lc code=end

