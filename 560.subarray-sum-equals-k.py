#
# @lc app=leetcode id=560 lang=python3
#
# [560] Subarray Sum Equals K
#

# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        result = 0
        prefix_sum = [nums[0]]

        for i in range(1, len(nums)):
            prefix_sum.append(nums[i] + prefix_sum[i-1])
        
        m = dict()

        for i in range(len(nums)):
            if prefix_sum[i] == k:
                result += 1
            
            if prefix_sum[i] - k in m:
                result += m[prefix_sum[i] - k]

            m[prefix_sum[i]] = m.get(prefix_sum[i], 0)+ 1

        return result
        
# @lc code=end

