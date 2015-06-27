# -*- coding: utf-8 -*-
"""
Created on Fri Mar 20 20:37:43 2015

@author: Kuilin
"""

class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        return bin(n).count('1')

obj = Solution()
sumbits = obj.hammingWeight(11)