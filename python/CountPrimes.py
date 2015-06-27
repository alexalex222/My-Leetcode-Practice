# -*- coding: utf-8 -*-
"""
Created on Sat May 30 09:40:26 2015

@author: Kuilin
"""

class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n < 2:
            return 0
        l = [True] * n
        l[0] = False
        l[1] = False
        i = 2
        while i*i < n:
            if l[i]:
                j = i + i
                while j < n:
                    l[j] = False
                    j = j + i
            i = i + 1
        count = 0
        for t in l:
            if t:
                count = count + 1
        return count
        