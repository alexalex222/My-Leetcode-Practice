# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 10:48:34 2015

@author: Kuilin
"""

class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        number = 0
        for char in s:
            number = number*26 + (ord(char) - ord('A') + 1)
        return number
        
    # @return a string
#    def convertToTitle(self, num):
#        titl = ''
#        while num:
#            titl = chr(ord('A') + (num-1)%26) + titl
#            num = (num-1)/26
#        return titl

obj = Solution()
number = obj.titleToNumber('AA')
#title = obj.titleToNumber(28)
