from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        dup_count = 0
        for i in range(len(nums)):
            if nums[i] == val:
                dup_count += 1
            else:
                nums[i - dup_count] = nums[i]
        return len(nums) -dup_count