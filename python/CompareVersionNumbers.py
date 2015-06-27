# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 12:17:01 2015

@author: Kuilin
"""

class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        from distutils.version import LooseVersion
        if LooseVersion(version1) > LooseVersion(version2):
            return 1
        elif LooseVersion(version1) < LooseVersion(version2):
            return -1
        else:
            return 0

obj = Solution()
version1 = '0.1'
version2 = '1.1'
result = obj.compareVersion(version1, version2)




