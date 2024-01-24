#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#

# @lc code=start
import numpy 

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = dict()
        for num in nums:
            if num not in m:
                m[num] = 1
            else:
                m[num] += 1
        
        elements_list = list(m.keys())
        cnt = list(m.values())
        idx = sorted(range(len(cnt)), key=cnt.__getitem__)
        
        return elements_list[idx][-k:]
        
# @lc code=end

