# -*- coding: utf-8 -*-
"""
Created on Sat May 30 16:58:58 2015

@author: Kuilin
"""

a = ''
c = a.split()
b = a[::-1]

s = ''


class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        lastword = s[::-1].split()
        if len(c) == 0:
            return 0
        else:
            return len(lastword[0])
        

mysol = Solution()
result = mysol.lengthOfLastWord(a)