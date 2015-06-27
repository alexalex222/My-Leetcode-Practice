# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 15:38:20 2015

@author: Kuilin
"""

class Solution:
    # @return an integer
    def reverse(self, x):
        if x >= 0:
            sign = 1
        else:
            sign = -1
        y = str(abs(x))
        y_rev = ''
        for i in range(len(y)):
            y_rev =  y[i] + y_rev
        z = int(y_rev)
        if z*sign > 2**31-1 or z*sign < -2**31:
            return 0
        else:
            return z*sign
            
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        n_rev = int('{0:032b}'.format(n)[::-1],2)
        return n_rev
        
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def rotate(self, nums, k):
        length = len(nums)
        k %= length
        self.reverse_num(nums,0,length-k)
        self.reverse_num(nums,length-k,length)
        self.reverse_num(nums,0,length)
        
    def reverse_num(self, nums, start, end):
        for x in range(start,(start+end)//2):
            temp = nums[x]
            nums[x] = nums[start+end-x-1]
            nums[start+end-x-1] = temp
                
        
obj = Solution()
#a = obj.reverse(900000)
#bit_rev = '{0:32b}'.format(43261596)[::-1]
#n_rev = obj.reverseBits(43261596)

my_nums = [1,2,3,4,5,6,7]
obj.rotate(my_nums,3)