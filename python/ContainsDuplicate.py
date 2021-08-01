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
        num_pos_dict = dict()

        for i in range(len(nums)):
            if nums[i] not in num_pos_dict:
                num_pos_dict[nums[i]] = i
            else:
                if i - num_pos_dict[nums[i]] <= k:
                    return True
                else:
                    num_pos_dict[nums[i]] = i
        
        return False