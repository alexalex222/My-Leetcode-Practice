# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 13:35:03 2015

@author: Kuilin
"""

class Solution:
    # @return an integer
    def romanToInt(self, s: str) -> int:
        rom_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total_num = 0
        current_num = 0
        
        for i in range(len(s) - 1):
            current_num = rom_dict[s[i]]
            if rom_dict[s[i]] < rom_dict[s[i + 1]]:
                total_num -= current_num
            else:
                total_num += current_num
        
        total_num += rom_dict[s[-1]]
        return total_num

        
        
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