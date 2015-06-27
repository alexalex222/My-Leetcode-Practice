# -*- coding: utf-8 -*-
"""
Created on Fri Mar 20 20:54:19 2015

@author: Kuilin
"""

class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        i = 1
        z = 0
        while (n/5**i) >= 1:
            z = z + n//5**i
            i = i + 1
        return z
        
obj = Solution()
zeros = obj.trailingZeroes(4617)
