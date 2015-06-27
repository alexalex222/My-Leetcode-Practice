# -*- coding: utf-8 -*-
"""
Created on Sat May 30 08:49:50 2015

@author: Kuilin
"""

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        dic = dict()
        for index in range(0,len(s)):
            if s[index] in dic.keys():
                temp = dic[s[index]]
                if not temp == t[index]:
                    return False
            elif t[index] in dic.values():return False
            else: dic[s[index]] = t[index]
        return True

mysol = Solution
s = 'egg'
t = 'add'
result = mysol.isIsomorphic(s, t)