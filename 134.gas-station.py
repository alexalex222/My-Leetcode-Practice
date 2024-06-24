#
# @lc app=leetcode id=134 lang=python3
#
# [134] Gas Station
#

# @lc code=start
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        curr_surplus = 0
        total_surplus = 0
        start = 0
        for i in range(len(gas)):
            curr_surplus += gas[i] - cost[i]
            total_surplus += gas[i] - cost[i]
            if curr_surplus < 0:
                start = i + 1
                curr_surplus = 0

        if total_surplus < 0:
            return -1
        else:
            return start
        
# @lc code=end

