# %%
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        values = {}
        for index, num in enumerate(nums):
            remaining = target - num
            if remaining in values:
                return [index, values[remaining]]
            else:
                values[num] = index