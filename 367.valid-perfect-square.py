#
# @lc app=leetcode id=367 lang=python3
#
# [367] Valid Perfect Square
#

# @lc code=start
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left = 1
        right = num
        while left <= right:
            mid = (left + right) // 2
            s = mid * mid
            if s > num:
                right = mid - 1
            elif s < num:
                left = left + 1
            else:
                return True
        return False
        
# @lc code=end

