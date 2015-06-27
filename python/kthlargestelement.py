# -*- coding: utf-8 -*-
"""
Created on Sun May 31 21:06:35 2015

@author: Kuilin
"""


class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k):
        return sorted(nums, reverse = True)[k-1]

mysol = Solution()
a = [3,2,1,5,6,4]
result = mysol.findKthLargest(a,2)