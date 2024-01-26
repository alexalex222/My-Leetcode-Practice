#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#

# @lc code=start
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()
        result = []

        for idx, num in enumerate(nums):
            while q and (idx - q[0] > k - 1):
                q.popleft()

            while q and nums[q[-1]] < num:
                q.pop()

            q.append(idx)

            if idx >= k - 1:
                result.append(nums[q[0]])

        return result

            
        
# @lc code=end

