#
# @lc app=leetcode id=274 lang=python3
#
# [274] H-Index
#

# @lc code=start
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations = sorted(citations)
        
        left = 0
        n = len(citations)
        right = n - 1

        h_index = 0

        while left <= right:
            mid = (left + right) // 2
            if citations[mid] >= n - mid:
                h_index = max(h_index, n- mid)
                right = mid - 1
            else:
                left = mid + 1
        return h_index
        
        
# @lc code=end

