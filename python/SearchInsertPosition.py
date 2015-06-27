# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 20:39:48 2015

@author: Kuilin
"""

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        n = len(A)
        i = 0
        insertpos = 0
        if target <= A[0]:
            insertpos = 0
        elif target > A[n-1]:
            insertpos = n
        else:
            while i < n-1:
                if target > A[i] and target <= A[i+1]:
                    insertpos = i + 1
                    break
                else:
                    i = i + 1
        return insertpos
        
obj = Solution()
A = [1,3,5,6]
target = 7
pos = obj.searchInsert(A,target)
            
            