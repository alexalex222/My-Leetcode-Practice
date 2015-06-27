# -*- coding: utf-8 -*-
"""
Created on Sun May 31 09:30:43 2015

@author: Kuilin
"""

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def roblinear(self, nums):
        size = len(nums)
        odd = 0
        even = 0
        for i in range(size):
            if i%2 :
                odd = max(nums[i] + odd, even)
            else:
                even = max(nums[i] + even, odd)
        return max(odd, even)
        
    # @param {integer[]} nums
    # @return {integer}
    def robloop(self, nums):
        if len(nums) == 1:
            return nums[0]
        return max(self.roblinear(nums[1:]), self.roblinear(nums[:-1]))
        