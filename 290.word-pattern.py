#
# @lc app=leetcode id=290 lang=python3
#
# [290] Word Pattern
#

# @lc code=start
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        
        m = dict()
        m_rev = dict()
        for i in range(len(pattern)):
            p = pattern[i]
            word = words[i]
            if p not in m:
                m[p] = word
            elif m[p] != word:
                return False
            
            if word not in m_rev:
                m_rev[word] = p
            elif m_rev[word] != p:
                return False
        return True        
# @lc code=end

