# -*- coding: utf-8 -*-
"""
Created on Fri May 29 20:49:36 2015

@author: Kuilin
"""

class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if x < 0 :
            return False
        div = 1
        while x//div >= 10:
            div = div *10
        while x > 0:
            right = x // div
            left =  x % 10
            
            if (right != left):
                return False
        
            x = (x % div) // 10
            div = div / 100
        return True

mysol = Solution()
a = 12321
isPa = mysol.isPalindrome(a)
        
        

            