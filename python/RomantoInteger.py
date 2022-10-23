class Solution:
    def romanToInt(self, s: str) -> int:
        roman_int_dict = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        result_int = 0
        prev_char = None
        prev_val = 99999999
        for curr_char in s:
            curr_val = roman_int_dict[curr_char]
            if prev_char:
                prev_val = roman_int_dict[prev_char]             
        
            if curr_val <= prev_val:
                result_int += curr_val
            else:
                result_int += curr_val - 2 * prev_val

            prev_char = curr_char
        
        return result_int


if __name__ == '__main__':
    s = Solution()
    i = s.romanToInt("MCMXCIV")
    print(i)
