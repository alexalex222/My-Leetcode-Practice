#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        left = 0
        m = dict()
        max_len = 0

        for right in range(n):
            c = s[right]
            if c not in m or m[c] < left:
                m[c] = right
                max_len = max(max_len, right - left + 1)
            else:
                left = m[c] + 1
                m[c] = right

        return max_len

        
# @lc code=end

