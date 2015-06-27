import java.util.Arrays;

public class Tester {
	public static void main (String[] args) {
		Solution Sol = new Solution();
		
		int[] a = new int[1];
		a[0] = 9;
		int[] b;
		b = Sol.plusOne(a);
		System.out.println(Arrays.toString(b));
			
		}
}