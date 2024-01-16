from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        value_index_pair = {}
        for idx, num in enumerate(nums):
            residual = target - num
            if residual in value_index_pair:
                return idx, value_index_pair[residual]
            else:
                value_index_pair[num] = idx