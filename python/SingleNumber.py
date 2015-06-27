# -*- coding: utf-8 -*-
"""
Created on Sun Mar 29 11:00:45 2015

@author: Kuilin
"""

class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        result = 0
        for i in A:
            result = result^i
        return result