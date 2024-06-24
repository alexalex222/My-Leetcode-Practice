#
# @lc app=leetcode id=454 lang=python3
#
# [454] 4Sum II
#

# @lc code=start
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        m = dict()
        for h in nums1:
            for i in nums2:
                m[h + i] = m.get(h + i, 0) + 1
        ans = 0
        for h in nums3:
            for i in nums4:
                ans += m.get(-h-i, 0)
        return ans
        
# @lc code=end

