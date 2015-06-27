# -*- coding: utf-8 -*-
"""
Created on Thu Mar 26 19:35:03 2015

@author: Kuilin
"""

class Solution:
    # @return a list of integers
    def grayCode(self, n):
        code = []
        size = 2**n
        for i in range(size):
            code.append((i>>1)^i)
        return code