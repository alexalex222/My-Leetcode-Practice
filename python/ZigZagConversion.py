# -*- coding: utf-8 -*-
"""
Created on Sun Mar 22 10:49:15 2015

@author: Kuilin
"""

class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows == 1:
            return s
        sf = ''
        dire = 1
        flag = ['' for i in range(nRows)]
        i = 0
        for k in range(len(s)):
            flag[i] += s[k]
            if (i == 0 and k != 0) or (i == nRows -1):
                dire = - dire
            i = i + dire
        for j in range (nRows):
            sf = sf + flag[j]
        return sf

obj = Solution()
test_str = 'PAYPALISHIRING'
out_str = obj.convert(test_str, 3)