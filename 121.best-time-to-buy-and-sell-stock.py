#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prev_low = float('inf')
        max_profit = 0
        for num in prices:
            if num < prev_low:
                prev_low = num
            max_profit = max(max_profit, num - prev_low)
        return max_profit
    
# @lc code=end

