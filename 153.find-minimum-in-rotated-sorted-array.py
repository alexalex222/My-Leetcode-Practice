#
# @lc app=leetcode id=153 lang=python3
#
# [153] Find Minimum in Rotated Sorted Array
#

# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        if nums[left] <= nums[right]:
            return nums[0]
        
        curr_min = nums[0]
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < curr_min: curr_min = nums[mid]

            if nums[mid] <= nums[right]:
                right = mid - 1
            else:
                left = mid + 1

        return curr_min

        
# @lc code=end

