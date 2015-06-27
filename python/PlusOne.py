# -*- coding: utf-8 -*-
"""
Created on Mon Mar 23 19:41:23 2015

@author: Kuilin
"""

class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        n = len(digits)
        result = [0] * n
        addone = True
        for i in reversed(range(n)):
            if addone:
                temp = digits[i] + 1
                if temp == 10:
                    result[i] = 0
                    addone = True
                    if i == 0:
                        result = [1] + result
                else:
                    result[i] = temp
                    addone = False
            else:
                result[i] = digits[i]
        return result
    
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        return bin(int(a,2) + int(b,2))[2:]

obj = Solution()
test_in = [9,9,9,9,9]
test_out = obj.plusOne(test_in)

a = '11'
b = '11'

c = obj.addBinary(a,b)