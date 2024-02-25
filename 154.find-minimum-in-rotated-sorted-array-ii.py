#
# @lc app=leetcode id=154 lang=python3
#
# [154] Find Minimum in Rotated Sorted Array II
#

# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            # left part is sorted, the min is in the right part
            if nums[mid] > nums[right]:
                left = mid + 1
            # right part is sorted, the min is in the left part
            elif nums[mid] < nums[left]:
                right = mid
                left += 1   # obviously, current nums[left] is not the min
            else:   # nums[left] <= nums[mid] <= nums[right]
                right -= 1
        return nums[left]


        
# @lc code=end

