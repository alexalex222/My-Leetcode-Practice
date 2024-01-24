#
# @lc app=leetcode id=205 lang=python3
#
# [205] Isomorphic Strings
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        list_1 = []
        list_2 = []
        for i in range(len(s)):
            if s.index(s[i]) != t.index(t[i]):
                return False
        return True

# @lc code=end

