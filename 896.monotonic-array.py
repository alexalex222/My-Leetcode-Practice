#
# @lc app=leetcode id=896 lang=python3
#
# [896] Monotonic Array
#

# @lc code=start
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) < 3: return True

        prev_diff = nums[1] - nums[0]

        for i in range(2, len(nums)):
            curr_diff = nums[i] - nums[i - 1]
            if curr_diff * prev_diff < 0:
                return False
            else:
                prev_diff += curr_diff

        return True
        
# @lc code=end

