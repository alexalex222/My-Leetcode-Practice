#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        self.nums1 = nums1
        self.nums2 = nums2
        n1 = len(nums1)
        n2 = len(nums2)
        total = n1 + n2
        if total % 2 == 1:
            return self.find_kth(total//2 + 1, 0, 0)
        else:
            return (self.find_kth(total//2 + 1, 0, 0) + self.find_kth(total//2, 0, 0)) / 2

    def find_kth(self, k, start1, start2):
        # k must start from 1
        # think about what if k starts from 0
        if start1 >= len(self.nums1): return self.nums2[start2 + k - 1]
        if start2 >= len(self.nums2): return self.nums1[start1 + k - 1]
        if k == 1: return min(self.nums1[start1], self.nums2[start2])

        # if we are here, k >= 2
        m1 = start1 + k // 2 - 1
        mid_num_1 = float('inf')
        m2 = start2 + k // 2 - 1
        mid_num_2 = float('inf')
        if m1 < len(self.nums1): mid_num_1 = self.nums1[m1]
        if m2 < len(self.nums2): mid_num_2 = self.nums2[m2]

        if mid_num_1 < mid_num_2:
            return self.find_kth(k - k//2, m1 + 1, start2)
        else:
            return self.find_kth(k - k//2, start1, m2 + 1)


# @lc code=end

