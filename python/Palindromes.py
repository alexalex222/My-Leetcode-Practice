class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Special cases:
        # As discussed above, when x < 0, x is not a palindrome.
        # Also if the last digit of the number is 0, in order to be a palindrome,
        # the first digit of the number also needs to be 0.
        # Only 0 satisfy this property.
        if(x < 0) or (x % 10 == 0 and x != 0):
            return False
        
        reverted = 0
        while(x > reverted):
            reverted = reverted * 10 + x % 10
            x = x // 10

        return (x == reverted) or (x == reverted // 10)

        

            