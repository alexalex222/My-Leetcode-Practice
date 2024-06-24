#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        jump_dist = 0
        for n in nums:
            if jump_dist < 0:
                return False
            elif n > jump_dist:
                jump_dist = n
            jump_dist -= 1
        return True
        
# @lc code=end

