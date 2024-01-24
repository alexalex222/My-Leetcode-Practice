#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#

# @lc code=start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m = dict()
        for i in range(len(s)):
            if s[i] not in m:
                m[s[i]] = 1
            else:
                m[s[i]] += 1

        for i in range(len(t)):
            if t[i] not in m:
                return False
            else:
                m[t[i]] -= 1

        for k, v in m.items():
            if v != 0:
                return False
        return True
            

        
# @lc code=end

