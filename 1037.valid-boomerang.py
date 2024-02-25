#
# @lc app=leetcode id=1037 lang=python3
#
# [1037] Valid Boomerang
#

# @lc code=start
import math 
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        p = points
        return (p[0][0] - p[1][0]) * (p[0][1] - p[2][1]) != (p[0][0] - p[2][0]) * (p[0][1] - p[1][1])
        

# @lc code=end

