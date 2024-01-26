#
# @lc app=leetcode id=389 lang=python3
#
# [389] Find the Difference
#

# @lc code=start
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        d = dict()
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1

        for c in t:
            if c in d:
                d[c] -= 1
                if d[c] < 0: return c
            else:
                return c
        
        
# @lc code=end

