# -*- coding: utf-8 -*-
"""
Created on Sun Mar 29 15:49:03 2015

@author: Kuilin
"""

class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        num = sorted(num)
        n = len(num)
        return num[n//2]