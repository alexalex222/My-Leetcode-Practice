# -*- coding: utf-8 -*-
"""
Created on Mon Mar 23 19:30:53 2015

@author: Kuilin
"""

class Solution:
    # @param matrix, a list of lists of integers
    # @return nothing (void), do not return anything, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        numRows = len(matrix)
        numCols = len(matrix[0])
        zeroRow = [False for i in range(numRows)]
        zeroCol = [False for j in range(numCols)]
        for i in range(numRows):
            for j in range(numCols):
                if matrix[i][j] == 0:
                    zeroRow[i] = True
                    zeroCol[j] = True
        for i in range(numRows):
            for j in range(numCols):
                if zeroRow[i] or zeroCol[i] :
                    matrix[i][j] = 0
    
    # @param matrix, a list of lists of integers
    # @return nothing (void), do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(n):
            matrix[i].reverse()
