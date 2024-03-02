#
# @lc app=leetcode id=300 lang=python3
#
# [300] Longest Increasing Subsequence
#

# @lc code=start
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        self.subs = []
        for i in range(len(nums)):
            x = nums[i]
            if len(self.subs) == 0 or self.subs[-1] < x:
                self.subs.append(x)
            else:
                idx = self.find_idx(x)
                self.subs[idx] = x
        
        return len(self.subs)
                
    def find_idx(self, x):
        left = 0
        right = len(self.subs) - 1
        while left <= right:
            mid = (left + right) // 2
            if self.subs[mid] == x:
                return mid 
            elif self.subs[mid] > x:
                right = mid - 1
            else:
                left = mid + 1
        if self.subs[left] >= x:
            return left
        else:
            return left + 1
        
# @lc code=end

