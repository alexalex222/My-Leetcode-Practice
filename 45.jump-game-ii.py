#
# @lc app=leetcode id=45 lang=python3
#
# [45] Jump Game II
#

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            nums[i] = max(nums[i] + i, nums[i - 1])

        ind = 0
        ans = 0
        while(ind < len(nums) - 1):
            ans += 1
            ind = nums[ind]
        return ans
        
# @lc code=end

