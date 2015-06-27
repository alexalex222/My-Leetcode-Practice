# -*- coding: utf-8 -*-
"""
Created on Wed Mar 25 19:29:38 2015

@author: Kuilin
"""

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        ThisSum = 0
        MaxSum = -10000
        
        for i in range( 0, len(A) ):
            if ThisSum < 0:
                ThisSum = 0
            ThisSum = ThisSum + A[ i ]
            MaxSum = max( ThisSum, MaxSum )

        return MaxSum