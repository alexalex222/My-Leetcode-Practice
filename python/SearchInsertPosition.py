from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0 or nums is None:
            return 0
        
        left = 0
        right = len(nums) - 1
        while (left < right):
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid
            else:
                left = mid + 1

        if nums[left] < target:
            return left + 1
        else:
            return left
            
            