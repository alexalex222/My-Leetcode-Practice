from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        value_pairs = {}
        for idx, num in enumerate(nums):
            residual = target - num
            if residual in value_pairs:
                return idx, value_pairs[residual]
            else:
                value_pairs[num] = idx