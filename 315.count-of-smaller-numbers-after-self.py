#
# @lc app=leetcode id=315 lang=python3
#
# [315] Count of Smaller Numbers After Self
#

# @lc code=start
import bisect
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        arr = sorted(nums)
        ans = []

        for num in nums:
            i = bisect.bisect_left(arr,num)    #   <-- 2a)
            ans.append(i)               #   <-- 2b)
            del arr[i]                  #   <-- 2c)
        
        return ans
        
# @lc code=end

