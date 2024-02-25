#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            
            # the left to mid part is sorted
            if nums[left] <= nums[mid]:
                # the target is between left and mid
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                # the target is in the right part
                else:
                    left = mid + 1
            
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1

        
# @lc code=end

