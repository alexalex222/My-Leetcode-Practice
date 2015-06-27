# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 14:42:22 2015

@author: Kuilin
"""

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        while elem in A:
            A.remove(elem)
        return len(A)
        
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if len(A) == 0:
            return 0
        j = 0
        for i in range(0, len(A)):
            if A[i] != A[j]:
                A[i], A[j+1] = A[j+1], A[i]
                j = j + 1
        return j+1

test_list = [1, 2, 3, 4, 4, 4, 5]
target = sorted(set(test_list))
