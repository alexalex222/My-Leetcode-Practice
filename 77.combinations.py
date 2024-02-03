#
# @lc app=leetcode id=77 lang=python3
#
# [77] Combinations
#

# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.result = []
        # self.dfs(n, k, 1, [])
        return self.result
    

    def dfs(self, n, k, level, curr_comb):
        if len(curr_comb) == k:
            self.result.append(curr_comb)
            return
        
        for i in range(level, n+ 1):
            curr_comb.append(i)
            self.dfs(n, k, i+1, curr_comb)
            curr_comb.pop()
        

        
# @lc code=end

