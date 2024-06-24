#
# @lc app=leetcode id=228 lang=python3
#
# [228] Summary Ranges
#

# @lc code=start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        ans = []
        start = nums[0]
        stop = nums[0]

        for i in range(1, len(nums) + 1):
            if i < len(nums) and nums[i] == stop + 1:
                stop = nums[i]
            else:
                if stop == start:
                    curr_range = str(start)
                else:
                    curr_range = str(start) + "->" + str(stop)
                ans.append(curr_range)

                if i < len(nums):
                    start = nums[i]
                    stop = nums[i]

        return ans

        
# @lc code=end

