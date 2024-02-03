#
# @lc app=leetcode id=912 lang=python3
#
# [912] Sort an Array
#

# @lc code=start
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.merge_sort(nums)
    
    def merge_sort(self, nums):
        if len(nums) == 1: return nums

        mid = len(nums) // 2
        left = self.merge_sort(nums[:mid])
        right = self.merge_sort(nums[mid:])

        return self.merge(left, right)
    
    def merge(self, left, right):
        if left[-1] <= right[0]:
            return left + right
        
        if right[-1] < left[0]:
            return right + left

        merged = []
        i = 0
        j = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                j += 1
        
        if i < len(left):
            merged = merged + left[i:]

        if j < len(right):
            merged = merged + right[j:]

        return merged
        
# @lc code=end

