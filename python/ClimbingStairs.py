# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 15:04:53 2015

@author: Kuilin
"""

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        a, b = 1, 2
        if n <= 1:
            return a
        elif n == 2:
            return b
        else:
            m = n -2 
            while m:
                a, b = b, a+b
                m = m-1
            return b

obj = Solution()
result = obj.climbStairs(5)