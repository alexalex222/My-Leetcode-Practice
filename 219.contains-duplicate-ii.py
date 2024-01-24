#
# @lc app=leetcode id=219 lang=python3
#
# [219] Contains Duplicate II
#

# @lc code=start
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m = dict()
        for i in range(len(nums)):
            num = nums[i]
            if num not in m:
                m[num] = i
            else:
                distance = i - m[num]
                if distance <= k:
                    return True
                else:
                    m[num] = i
        return False
        
# @lc code=end

