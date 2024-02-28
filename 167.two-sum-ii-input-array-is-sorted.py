#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        result = []
        while left < right:
            s = numbers[left] + numbers[right]
            if s == target:
                result.append(left + 1)
                result.append(right + 1)
                break
            elif s < target:
                left += 1
            else:
                right -= 1
        
        return result
        
# @lc code=end

