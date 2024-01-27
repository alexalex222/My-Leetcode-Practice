#
# @lc app=leetcode id=645 lang=python3
#
# [645] Set Mismatch
#

# @lc code=start
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        m = {i: 1 for i in range(1, len(nums) + 1)}

        for num in nums:
            m[num] -= 1

        dup = -1
        miss = -1
        for k, v in m.items():
            if v == -1:
                dup = k
            if v == 1:
                miss = k
        return [dup, miss]
        
# @lc code=end

