#
# @lc app=leetcode id=378 lang=python3
#
# [378] Kth Smallest Element in a Sorted Matrix
#

# @lc code=start
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        self.matrix = matrix
        self.rows = len(matrix)
        self.cols = len(matrix[0])

    def find_kth(self, k, start):
        row = start // self.cols
        col = start % self.cols


        
# @lc code=end

