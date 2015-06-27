public class Solution {
    public double myPow(double x, int n) {
      return Math.pow(x,n);
    }
		
		public int mySqrt(int x) {
      return (int)Math.sqrt(x);
    }
		
		public int[] plusOne(int[] digits) {
			int size = digits.length;
			int addone = 1;
			for (int i = size - 1; i >= 0; i--) {
				int digit = (digits[i] + addone)%10;
				addone = (digits[i] + addone) / 10;
				digits[i] = digit;
				if ( addone == 0) {
					return digits;
				}
			}
			int[] result = new int[size + 1];
			result[0] = 1;
			return result;
    }
		
		
}