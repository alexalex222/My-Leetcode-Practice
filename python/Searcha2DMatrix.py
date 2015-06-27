# -*- coding: utf-8 -*-
"""
Created on Tue Mar 24 21:00:52 2015

@author: Kuilin
"""

class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
        numRows = len(matrix)
        numCols = len(matrix[0])
        i = 0
        j = numCols - 1
        while i < numRows and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j = j -1 
            else:
                i = i + 1
        return False
        
    # @return a list of lists of integer
    def generateMatrix(self, n):
        smatrix = [[0 for i in range(n)] for j in range(n)]
        elem = 0
        direction = 0
        topbound = 0
        botbound = n -1 
        leftbound = 0
        rightbound = n -1 
        i = 0
        while elem < n**2:
            if direction == 0:
                for i in range(leftbound,rightbound+1):
                    elem = elem + 1
                    smatrix[topbound][i] = elem
                topbound = topbound + 1
            elif direction == 1:
                for i in range(topbound,botbound+1):
                    elem = elem + 1
                    smatrix[i][rightbound] = elem
                rightbound = rightbound - 1
            elif direction == 2:
                for i in range(rightbound, leftbound - 1, -1):
                    elem = elem + 1
                    smatrix[botbound][i] = elem
                botbound = botbound - 1
            else:
                for i in range(botbound, topbound-1, -1):
                    elem = elem + 1
                    smatrix[i][leftbound] = elem
                leftbound = leftbound + 1
            direction = (direction + 1)%4
        return smatrix
        
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def spiralOrder(self, matrix):
        expand = []
        if len(matrix) == 0:
            return expand
        n = len(matrix)
        m = len(matrix[0])
        direction = 0
        topbound = 0
        botbound = n -1 
        leftbound = 0
        rightbound = m -1 
        elem = 0
        while elem < n*m:
            if direction == 0:
                for i in range(leftbound,rightbound+1):
                    elem = elem + 1
                    expand.append(matrix[topbound][i])
                topbound = topbound + 1
            elif direction == 1:
                for i in range(topbound,botbound+1):
                    elem = elem + 1
                    expand.append(matrix[i][rightbound])
                rightbound = rightbound - 1
            elif direction == 2:
                for i in range(rightbound, leftbound - 1, -1):
                    elem = elem + 1
                    expand.append(matrix[botbound][i])
                botbound = botbound - 1
            else:
                for i in range(botbound, topbound-1, -1):
                    elem = elem + 1
                    expand.append(matrix[i][leftbound])
                leftbound = leftbound + 1
            direction = (direction + 1)%4
        return expand
    
                    
obj = Solution()
A = obj.generateMatrix(4)            
B = obj.spiralOrder([])            
    
a = [[0 for i in range(4)] for j in range(3)]