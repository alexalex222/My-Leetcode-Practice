# -*- coding: utf-8 -*-
"""
Created on Fri Mar 20 19:48:00 2015

@author: Kuilin
"""



class Solution:
# @return a list of lists of integers
    def generate(self, numRows):
        pas_tri = []
        for i in range(numRows):
            pas_tri.append([1]*(i+1))
            if i>1 :
                for j in range(1,i):
                    pas_tri[i][j]=pas_tri[i-1][j-1]+pas_tri[i-1][j]
        return pas_tri
        
    # @return a list of integers
    def getRow(self, rowIndex):
        if rowIndex < 0:
            return []
        currentRow = [1]*(rowIndex+1)
        for i in range(1, rowIndex+1):
            for j in range(i-1, 0 , -1):
                currentRow[j] = currentRow[j] + currentRow[j-1]
        return currentRow
        

obj = Solution()
my_tri = obj.generate(9)
current_row = obj.getRow(4)
print(current_row)
