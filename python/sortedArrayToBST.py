from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right



class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.get_tree(nums, 0, len(nums) - 1)

    def get_tree(self, nums: List[int], left_idx: int, right_idx: int):
        if left_idx > right_idx:
            return None

        mid = (left_idx + right_idx) // 2
        root = TreeNode(val=nums[mid])
        root.left = self.get_tree(nums, left_idx, mid-1)
        root.right = self.get_tree(nums, mid+1, right_idx)
        return root