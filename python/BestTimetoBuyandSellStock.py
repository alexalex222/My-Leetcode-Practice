# -*- coding: utf-8 -*-
"""
Created on Mon Mar 30 20:48:48 2015

@author: Kuilin
"""

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfitII(self, prices):
        profit = 0
        for i in range(len(prices)-1):
            if prices[i+1] > prices[i]:
                profit = profit + prices[i+1] - prices[i]
        return profit
        
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if not prices:
            return 0
        else:
            minprice = prices[0]
            profit = 0
            for currprice in prices:
                minprice = min(currprice, minprice)
                profit = max(profit, currprice - minprice)
            return profit