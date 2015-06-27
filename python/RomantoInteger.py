# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 13:35:03 2015

@author: Kuilin
"""

class Solution:
    # @return an integer
    def romanToInt(self, s):
        rome_tup = ('I','V','X', 'L', 'C', 'D', 'M')
        num_tup = (1, 5, 10, 50, 100, 500, 1000)
        num = 0
        current_num = 0
        length = len(s)
        for i in range(length-1):
            current_num = num_tup[rome_tup.index(s[i])]
            if num_tup[rome_tup.index(s[i])] < num_tup[rome_tup.index(s[i+1])]:
                num = num - current_num
            else:
                num = num + current_num
        num = num + num_tup[rome_tup.index(s[length-1])]
        return num
        
    # @return a string
    def intToRoman(self, num):
        romenum = ''
        num_tup = ( 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 )
        rome_tup = [ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" ]
        for i in range(len(rome_tup)):
            while num >= num_tup[i]:
                num = num - num_tup[i]
                romenum = romenum + rome_tup[i]
        return romenum

obj = Solution()

num = 1
romenum = obj.intToRoman(num)