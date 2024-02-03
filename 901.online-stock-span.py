#
# @lc app=leetcode id=901 lang=python3
#
# [901] Online Stock Span
#

# @lc code=start
class StockSpanner:

    def __init__(self):
        self.local_max = []
        self.timestamp = 0
        

    def next(self, price: int) -> int:
        self.timestamp += 1
        curr_record = {'ts': self.timestamp, 'price': price}

        while(self.local_max and price >= self.local_max[-1]['price']):
            self.local_max.pop()

        self.local_max.append(curr_record)

        if len(self.local_max) > 1:
            return self.local_max[-1]['ts'] - self.local_max[-2]['ts']
        else:
            return self.timestamp
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

