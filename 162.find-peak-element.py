#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#

# @lc code=start
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if mid - 1 < 0:
                left_num = float('-inf')
            else:
                left_num = nums[mid - 1]
            
            if mid + 1 >= len(nums):
                right_num = float('-inf')
            else:
                right_num = nums[mid + 1]
            
            if left_num < nums[mid] and nums[mid] > right_num:
                return mid
            elif nums[mid] <= left_num:
                right = mid - 1
            else:
                left = mid + 1
        
        return -1
            
        
# @lc code=end

