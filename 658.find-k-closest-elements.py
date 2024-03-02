#
# @lc app=leetcode id=658 lang=python3
#
# [658] Find K Closest Elements
#

# @lc code=start
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if x <= arr[0]:
            return arr[:k]
        
        if x >= arr[-1]:
            return arr[-k:]
        
        left = 0
        right = len(arr) - 1

        closest_idx = -1

        while left <= right:
            mid = (left + right) // 2
            if arr[mid] == x:
                closest_idx = mid
                break

            if arr[mid] > x:
                right = mid -1 
            else:
                left = mid + 1

        if left > right:
            left, right = right, left

        if closest_idx == -1:
            left_dist = abs(arr[left] - x)
            right_dist = abs(arr[right] - x)

            if left_dist <= right_dist:
                closest_idx = left
            else:
                closest_idx = right        

        k -= 1
        left = closest_idx - 1
        right = closest_idx + 1

        while k > 0:
            if left < 0:
                right += 1
            elif right >= len(arr):
                left -= 1
            else:
                left_dist = abs(arr[left] - x)
                right_dist = abs(arr[right] - x)

                if left_dist <= right_dist:
                    left -= 1
                else:
                    right += 1
            k -= 1

        return arr[left+1:right]


# @lc code=end

