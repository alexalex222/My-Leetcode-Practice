# -*- coding: utf-8 -*-
"""
Created on Sat May 30 16:42:32 2015

@author: Kuilin
"""

class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        l = set()
        sum = n
        while sum != 1:
            n = sum
            sum = 0
            while n > 0:
                sum = sum + (n%10)*(n%10)
                n = n//10
            if sum in l:
                return False
            else:
                l.add(sum)
        return True
        
sol = Solution()
a = 19
result = sol.isHappy(a)