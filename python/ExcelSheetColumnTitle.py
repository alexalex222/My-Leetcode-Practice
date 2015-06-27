# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 11:38:19 2015

@author: Kuilin
"""

class Solution:
    # @return a string
    def convertToTitle(self, num):
        titl = ''
        while num:
            titl = chr(ord('A') + (num-1)%26) + titl
            num = (num-1)//26
        return titl

obj = Solution()

title = obj.convertToTitle(28)