#
# @lc app=leetcode id=1122 lang=python3
#
# [1122] Relative Sort Array
#

# @lc code=start
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        result = []
        common_dict = {}
        unique_dict = {}
        for num in arr1:
            if num in arr2:
                common_dict[num] = common_dict.get(num, 0) + 1
            else:
                unique_dict[num] = unique_dict.get(num, 0) + 1

        for num in arr2:
            result += [num] * common_dict[num]

        trail_list = []
        for k, v in unique_dict.items():
            trail_list += [k] * v

        trail_list.sort()

        return result + trail_list
        
# @lc code=end

