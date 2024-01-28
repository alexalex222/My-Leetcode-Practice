#
# @lc app=leetcode id=122 lang=python3
#
# [122] Best Time to Buy and Sell Stock II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(0, len(prices) - 1):
            diff = prices[i + 1] - prices[i]
            max_profit += max(diff, 0)

        return max_profit
        
# @lc code=end

