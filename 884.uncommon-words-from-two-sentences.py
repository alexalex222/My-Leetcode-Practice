#
# @lc app=leetcode id=884 lang=python3
#
# [884] Uncommon Words from Two Sentences
#

# @lc code=start
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s = s1 + " " + s2
        word_list = s.split()
        d = dict()
        for w in word_list:
            if w in d.keys():
                d[w] += 1
            else:
                d[w] = 1
        
        result = []
        for k, v in d.items():
            if v == 1:
                result.append(k)
        return result
# @lc code=end

