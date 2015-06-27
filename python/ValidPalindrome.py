# -*- coding: utf-8 -*-
"""
Created on Sun May 31 10:49:08 2015

@author: Kuilin
"""

a = "A man, a plan, a canal: Panama"
b = "1a2"


class Solution:
    # @param {string} s
    # @return {boolean}
    def isPalindrome(self, s):
        import re
        a = " ".join(re.findall("[a-zA-Z0-9]+", s.lower()))
        b = a.split()
        c = ''
        for i in range(len(b)):
            c = c + b[i]
        c1 = c[::-1]
        if c == c1:
            return True
        else:
            return False
mysol = Solution()
result = mysol.isPalindrome(b)