# -*- coding: utf-8 -*-
"""
Created on Thu Mar 26 20:21:56 2015

@author: Kuilin
"""



class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        import itertools
        import math
        n = len(num)
        numComb = math.factorial(n)
        B = list(itertools.permutations(num))
        for i in range(numComb):
            B[i] = list(B[i])
        return B
        
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        if not S:
            return []
        n = len(S)
        A = sorted(S)
        
    
        
        
a =[[1,2],[1,3] ,[1,2]]
b = map(a)
