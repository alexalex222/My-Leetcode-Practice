import re
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        carry = 1
        while (i >= 0):
            current_digit = digits[i]
            temp = current_digit + carry
            digits[i] = temp % 10
            carry = temp // 10
            i -= 1
        if carry == 0:
            return digits
        else:
            return [1] + digits

        