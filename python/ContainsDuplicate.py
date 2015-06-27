# -*- coding: utf-8 -*-
"""
Created on Fri May 29 21:05:25 2015

@author: Kuilin
"""


class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        b = set(nums)
        if len(nums) == len(b):
            return False
        else:
            return True
    
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                if nums[i] == nums[j]:
                    k_temp = j - i
                    if k_temp <= k:
                        return True
        return False