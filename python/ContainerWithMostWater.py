# -*- coding: utf-8 -*-
"""
Created on Fri Mar 27 18:36:45 2015

@author: Kuilin
"""

class Solution:
    # @return an integer
    def maxArea(self, height):
        left = 0
        right = len(height)-1
        res = 0
        while left < right:
            water = min(height[left], height[right])*(right-left)
            if res < water:
                res = water
            if height[left] < height[right]:
                left = left + 1
            else:
                right = right - 1
        return res