#
# @lc app=leetcode id=350 lang=python3
#
# [350] Intersection of Two Arrays II
#

# @lc code=start
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2): return self.intersect(nums2, nums1)

        cnt = dict()
        for num in nums1:
            cnt[num] = cnt.get(num, 0) + 1
        
        ans = []
        
        for num in nums2:
            if cnt.get(num, 0) > 0:
                ans.append(num)
                cnt[num] -= 1
        
        return ans
        
# @lc code=end

