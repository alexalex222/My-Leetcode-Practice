# -*- coding: utf-8 -*-
"""
Created on Thu Mar 26 19:14:32 2015

@author: Kuilin
"""

class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        n = len(A)
        for i in range(n-1):
            for j in range(n-1-i):
                if A[j] > A[j+1]:
                    temp = A[j]
                    A[j] = A[j+1]
                    A[j+1] = temp

obj = Solution()
A = [0, 1, 2, 2, 1, 2, 1, 0]
obj.sortColors(A)