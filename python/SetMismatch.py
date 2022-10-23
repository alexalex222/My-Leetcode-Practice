from typing import List


class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        rep = -1
        missing = -1
        for idx in nums:
            if nums[abs(idx) - 1] > 0:
                nums[abs(idx) - 1] *= -1
            else:
                rep = abs(idx)
        
        for idx in range(len(nums)):
            if nums[idx] > 0:
                missing = idx + 1

        return [rep, missing]


if __name__ == '__main__':
    s = Solution()
    result = s.findErrorNums([2, 2])