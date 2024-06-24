#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        right = 0
        cumsum = 0
        min_len = len(nums) + 1
        while right < len(nums):
            cumsum += nums[right]

            if cumsum >= target:
                while(cumsum >= target):
                    min_len = min(min_len, right - left + 1)
                    cumsum -= nums[left]
                    left += 1

            right += 1

        if min_len == len(nums) + 1:
            return 0
        else:
            return min_len

        
# @lc code=end

