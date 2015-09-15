

import sun.reflect.generics.tree.Tree;

import java.util.*;
import java.util.regex.Matcher;

/**
 * Created by Kuilin on 8/5/2015.
 */
public class Solution {

    public int majorityElement(int[] nums) {
        if(nums.length == 1) return nums[0];
        Arrays.sort(nums);
        return nums[nums.length/2];
    }

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(numRows <= 0) return result;

        ArrayList<Integer> pre = new ArrayList<Integer>();
        pre.add(1);
        result.add(pre);

        for(int i = 2; i <= numRows; i++) {
            ArrayList<Integer> cur = new ArrayList<Integer>();
            cur.add(1);

            for(int j = 0; j < pre.size() - 1; j++) {
                cur.add(pre.get(j) + pre.get(j+1));
            }

            cur.add(1);

            result.add(cur);

            pre = cur;
        }

        return result;

    }

    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;

        char[] schars = s.toCharArray();
        char[] tchars = t.toCharArray();
        Arrays.sort(schars);
        Arrays.sort(tchars);
        for(int i = 0; i < s.length(); i++) {
            if(schars[i] != tchars[i]) return false;
        }
        return true;
    }

    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode m = root;
        if(m.val < p.val && m.val < q.val) return lowestCommonAncestor(m.right, p, q);
        else if(m.val > p.val && m.val > q.val) return lowestCommonAncestor(m.left, p, q);
        else return m;
    }

    public boolean isPowerOfTwo(int n) {
        return (n > 0 && ((n & (n-1)) == 0));
    }

    public TreeNode invertTree(TreeNode root) {
        if(root != null) {
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;

            invertTree(root.left);
            invertTree(root.right);

        }

        return root;
    }

    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(C < E || G < A) return (G - E)*(H - F) + (C - A)*(D - B);
        if(D < F || H < B) return (G - E)*(H - F) + (C - A)*(D - B);

        int right = Math.min(C, G);
        int left = Math.max(A, E);
        int top = Math.min(H, D);
        int bottom = Math.max(F, B);

        return (G - E)*(H - F) + (C - A)*(D - B) - (right - left)*(top - bottom);
    }

    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> mymap = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
            if(mymap.containsKey(nums[i])) {
                int pre = mymap.get(nums[i]);
                if(i - pre <= k) {
                    return true;
                } else {
                    mymap.put(nums[i], i);
                }
            } else {
                mymap.put(nums[i], i);
            }
        }

        return false;
    }

    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> myset = new HashSet<Integer>();
        for(int i : nums) {
            if(myset.contains(i)) {
                return true;
            } else {
                myset.add(i);
            }
        }
        return false;
    }

    public int reverse(int x) {
        long rev = 0;
        while(x != 0) {
            rev = rev*10 + x%10;
            x = x/10;
        }
        if(rev > Math.pow(2, 31)-1 || rev < -Math.pow(2, 31)) return 0;
        else return (int) rev;
    }

    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while(head != null) {
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> mymap = new HashMap<Character, Character>();
        for(int i = 0; i < s.length(); i++) {
            if(mymap.containsKey(s.charAt(i))) {
                if(t.charAt(i) != mymap.get(s.charAt(i))) return false;
            } else  if(mymap.containsValue(t.charAt(i))) return false;

            mymap.put(s.charAt(i), t.charAt(i));

        }
        return true;
    }

    public int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2) return n;

        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i =3; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }

    public ListNode deleteDuplicatesI(ListNode head) {
        if(head == null || head.next == null) return  head;

        ListNode cur = head;
        while(cur != null && cur.next != null) {
            if(cur.val == cur.next.val) cur.next = cur.next.next;
            else cur = cur.next;
        }

        return head;
    }

    public int maxSubArray(int[] nums) {
        int thissum = 0;
        int maxsum = Integer.MIN_VALUE;

        for(int i = 0; i < nums.length; i++) {
            if(thissum < 0) thissum = 0;
            thissum = thissum + nums[i];
            maxsum = Math.max(thissum, maxsum);
        }
        return maxsum;
    }

    public int maxProfitI(int[] prices) {
        if(prices == null || prices.length < 2) return 0;
        int minPrice = prices[0];
        int profit = 0;
        for(int curPrice : prices) {
            minPrice = Math.min(curPrice, minPrice);
            profit = Math.max(profit, curPrice - minPrice);
        }
        return profit;
    }

    public int maxProfitII(int[] prices) {
        int profit = 0;
        for(int i = 0; i < prices.length - 1; i++) {
            if(prices[i+1] - prices[i] > 0) profit += prices[i+1] - prices[i];
        }
        return profit;
    }

    public int maxProfitIII(int[] prices) {
        if(prices == null || prices.length < 2) return 0;
        int len = prices.length;
        int[] profitsFirst = new int[len];
        int[] profitsSecond = new int[len];
        int profit = 0;

        int minPirce = prices[0];
        for(int i = 1; i < len; i++) {
            minPirce = Math.min(minPirce, prices[i]);
            profitsFirst[i] = Math.max(profitsFirst[i-1], prices[i] - minPirce);
        }

        int maxPrice = prices[len-1];
        for(int i = len - 2; i >= 0; i--) {
            maxPrice = Math.max(maxPrice, prices[i]);
            profitsSecond[i] = Math.max(profitsSecond[i+1], maxPrice - prices[i]);
        }

        for(int i = 0; i < len; i++) profit = Math.max(profit, profitsFirst[i]+profitsSecond[i]);

        return profit;
    }

    public int hammingWeight(int n) {
        int count = 0;
        while(n != 0) {
            n = n & (n-1);
            count++;
        }
        return count;
    }

    public int titleToNumber(String s) {
        int number = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            number = number*26 + (c - 'A' + 1);
        }
        return number;
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        recursivePreorder(root, result);
        return result;
    }

    public void recursivePreorder(TreeNode p, List<Integer> l) {
        if(p != null) {
            l.add(p.val);
            recursivePreorder(p.left, l);
            recursivePreorder(p.right, l);
        }
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        recursiveInorder(root, result);
        return result;
    }

    public void recursiveInorder(TreeNode p, List<Integer> l) {
        if(p != null) {
            recursiveInorder(p.left, l);
            l.add(p.val);
            recursiveInorder(p.right, l);
        }
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        recursivePostorder(root, result);
        return result;
    }

    public void recursivePostorder(TreeNode p, List<Integer> l) {
        if(p != null) {
            recursivePostorder(p.left, l);
            recursivePostorder(p.right, l);
            l.add(p.val);
        }
    }

    public int addDigits(int num) {
        int result = 1 + ((num-1)%9);
        return result;
    }

    public boolean hasCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if(fast == slow) return true;
        }

        return false;
    }

    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(true) {
            if(fast == null || fast.next == null) return null;
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) break;
        }

        slow = head;
        while(slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        ListNode pa = headA;
        ListNode pb = headB;

        ListNode tailA = null;
        ListNode tailB = null;

        while(true) {
            if(pa == null) pa = headB;
            if(pb == null) pb = headA;

            if(pa.next == null) tailA = pa;
            if(pb.next == null) tailB = pb;

            if(tailA != null && tailB != null && tailA != tailB) return null;
            if(pa == pb) return pa;

            pa = pa.next;
            pb = pb.next;

        }
    }

    public ListNode removeElements(ListNode head, int val) {
        ListNode helper = new ListNode(0);
        helper.next = head;
        ListNode p = helper;

        while(p.next != null) {
            if(p.next.val == val) p.next = p.next.next;
            else p = p.next;
        }
        return helper.next;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null) return null;

        ListNode fast = head;
        ListNode slow = head;
        for(int i = 0; i < n; i++) fast = fast.next;

        if(fast == null) {
            head = head.next;
            return head;
        }

        while(fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        slow.next = slow.next.next;

        return head;
    }

    public void connect(TreeLinkNode root) {
        if(root == null) return;

        if(root.left != null) root.left.next = root.right;

        if(root.right != null && root.next != null) root.right.next = root.next.left;

        connect(root.left);
        connect(root.right);
    }

    public int numTrees(int n) {
        int[] count = new int[n+1];

        count[0] = 1;
        count[1] = 1;

        for(int i = 2; i < n+1; i++) {
            for(int j = 0; j < i; j++) {
                count[i] = count[i] + count[j]*count[i-j-1];
            }
        }
        return count[n];
    }

    public int kthSmallest(TreeNode root, int k) {
        TreeNode p = root;
        Stack<TreeNode> s = new Stack<TreeNode>();
        int ks = 0;

        while(p != null || !s.isEmpty()) {
            if(p != null) {
                s.push(p);
                p = p.left;
            } else {
                TreeNode t = s.pop();
                k--;
                if(k == 0) ks =  t.val;
                p = t.right;
            }
        }

        return ks;
    }

    public int[] productExceptSelf(int[] nums) {
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        int [] result = new int[nums.length];

        left[0] = 1;
        right[nums.length-1] = 1;

        for(int i = 0; i < nums.length-1; i++) {
            left[i+1] = left[i]*nums[i];
            right[nums.length-2-i] = right[nums.length-1 -i]*nums[nums.length-1-i];
        }

        for(int i = 0; i < nums.length; i++) result[i] = left[i]*right[i];

        return result;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums == null) return null;

        return sortedArrayToBST(nums, 0, nums.length-1);
    }

    public TreeNode sortedArrayToBST(int[] nums, int start, int end) {
        if(start > end) return null;
        int mid = (start+end)/2;
        TreeNode root = new TreeNode(nums[mid]);

        root.left = sortedArrayToBST(nums, start, mid-1);
        root.right = sortedArrayToBST(nums, mid+1, end);

        return root;
    }

    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int mid = 0;
        int min = nums[0];

        while(left < right -1) {
            mid = (left + right)/2;
            if(nums[mid] > nums[left]) {
                min = Math.min(min, nums[left]);
                left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                min = Math.min(min, nums[mid]);
                right = mid - 1;
            } else left++;
        }

        min = Math.min(min, nums[right]);
        min = Math.min(min, nums[left]);
        return min;
    }

    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<Integer>();
        result.add(0);
        for(int i = 0; i < n; i++) {
            int size = result.size();
            for(int j = 0; j < size; j++) {
                result.add(result.get(size - j - 1) + size);
            }
        }

        return result;
    }

    public void sortColors(int[] nums) {
        int redSt = 0;
        int blueSt = nums.length -1;
        int i = 0;
        while(i < blueSt + 1) {
            if(nums[i] == 0) {
                int temp = nums[i];
                nums[i] = nums[redSt];
                nums[redSt] = temp;
                redSt++;
                continue;

            }

            if(nums[i] == 2) {
                int temp = nums[i];
                nums[i] = nums[blueSt];
                nums[blueSt] = temp;
                blueSt--;
                continue;
            }

            i++;
        }
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) return true;
        else if(p != null && q != null && p.val == q.val) return (isSameTree(p.left, q.left) && isSameTree(p.right, q.right));
        else return false;
    }

    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        else {
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode p = dummy;
            while(p.next != null && p.next.next != null) {
                ListNode temp = p.next.next;
                p.next.next = temp.next;
                temp.next = p.next;
                p.next = temp;
                p = p.next.next;
            }
            return  dummy.next;
        }
    }

    public int uniquePaths(int m, int n) {
        if(m ==0 || n == 0) return 0;
        if(m == 1 || n == 1) return 1;

        int[][] dp = new int[m][n];
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int i = 0; i < n; i++) dp[0][i] = 1;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

    public int minPathSum(int[][] grid) {
        if(grid == null || grid.length == 0) return 0;

        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i = 1; i < n; i++) dp[0][i] = dp[0][i-1] + grid[0][i];

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i][j-1] + grid[i][j];
                else dp[i][j] = dp[i-1][j] + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }

    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][n - i - 1];
                matrix[n - j - 1][n - i - 1] = temp;
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n / 2; i++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = temp;
            }
        }
    }

    public int findPeakElement(int[] nums) {
        int left = 0;
        int right = nums.length-1;
        int mid = 0;
        while(left <= right) {
            if(left == right) return left;
            mid = (left + right)/2;
            if(nums[mid] > nums[mid+1]){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;

        if(Math.abs(treeDepth(root.right) - treeDepth(root.left)) > 1) return false;

        return (isBalanced(root.left) && isBalanced(root.right));
    }

    public int treeDepth(TreeNode root) {
        if(root == null) return 0;

        return 1+Math.max(treeDepth(root.left), treeDepth(root.right));
    }

    public void setZeroes(int[][] matrix) {
        int numRows = matrix.length;
        int numCols = matrix[0].length;

        boolean[] zeroRow = new boolean[numRows];
        boolean[] zeroCol = new boolean[numCols];

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < numCols; j++) {
                if(matrix[i][j] == 0) {
                    zeroRow[i] = true;
                    zeroCol[j] = true;
                }
            }
        }

        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < numCols; j++) {
                if(zeroRow[i]|| zeroCol[j]) matrix[i][j] = 0;
            }
        }
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(root == null) return result;
        Queue<TreeNode> treeNodeQueue = new LinkedList<TreeNode>();
        Queue<TreeNode> nextTreeNodeQueue = new LinkedList<TreeNode>();
        List<Integer> cur = new ArrayList<Integer>();
        treeNodeQueue.add(root);

        while(!treeNodeQueue.isEmpty()) {

            TreeNode tempNode = treeNodeQueue.poll();
            cur.add(tempNode.val);

            if(tempNode.left != null) nextTreeNodeQueue.add(tempNode.left);
            if(tempNode.right != null) nextTreeNodeQueue.add(tempNode.right);

            if(treeNodeQueue.isEmpty()) {
                treeNodeQueue = nextTreeNodeQueue;
                nextTreeNodeQueue = new LinkedList<TreeNode>();
                result.add(cur);
                cur = new ArrayList<Integer>();
            }
        }

        return result;
    }

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        if(root == null) return result;

        Queue<TreeNode> treeNodeQueue = new LinkedList<TreeNode>();
        Queue<TreeNode> nextTreeNodeQueue = new LinkedList<TreeNode>();
        List<Integer> cur = new ArrayList<Integer>();
        treeNodeQueue.add(root);

        while(!treeNodeQueue.isEmpty()) {

            TreeNode tempNode = treeNodeQueue.poll();
            cur.add(tempNode.val);

            if(tempNode.left != null) nextTreeNodeQueue.add(tempNode.left);
            if(tempNode.right != null) nextTreeNodeQueue.add(tempNode.right);

            if(treeNodeQueue.isEmpty()) {
                treeNodeQueue = nextTreeNodeQueue;
                nextTreeNodeQueue = new LinkedList<TreeNode>();
                result.add(cur);
                cur = new ArrayList<Integer>();
            }
        }

        List<List<Integer>> bottomResult = new ArrayList<List<Integer>>();
        for(int i = result.size()-1; i >= 0; i--) {
            bottomResult.add(result.get(i));
        }
        return bottomResult;
    }

    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return isSymmetric(root.left, root.right);
    }

    public boolean isSymmetric(TreeNode p, TreeNode q) {
        if(p == null && q == null) return true;
        else if(p == null || q == null) return false;

        return (p.val == q.val && isSymmetric(p.left, q.right) && isSymmetric(p.right, q.left));
    }

    public boolean isUgly(int num) {
        if(num < 0) return false;
        int[] factor = new int[]{2, 3, 5};
        for(int x : factor) {
            while(num%x == 0) num = num/x;
        }
        return num==1;
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<Integer>();
        if(matrix.length == 0) return result;
        int numElem = matrix.length*matrix[0].length;
        int direction = 0;
        int topbound = 0;
        int botbound = matrix.length - 1;
        int leftbound = 0;
        int rightbound = matrix[0].length - 1;


        while(numElem > 0) {
            if(direction == 0) {
                for(int i = leftbound; i <= rightbound; i++) {
                    result.add(matrix[topbound][i]);
                    numElem--;
                }
                topbound++;
            } else if(direction == 1) {
                for(int i = topbound; i <= botbound; i++) {
                    result.add(matrix[i][rightbound]);
                    numElem--;
                }
                rightbound--;
            } else if(direction == 2) {
                for(int i = rightbound; i >= leftbound; i--) {
                    result.add(matrix[botbound][i]);
                    numElem--;
                }
                botbound--;
            } else {
                for(int i = botbound; i >= topbound; i--) {
                    result.add(matrix[i][leftbound]);
                    numElem--;
                }
                leftbound++;
            }
            direction = (direction + 1)%4;
        }
        return result;
    }


    public int[][] generateMatrix(int n) {
        int[][] smatrix = new int[n][n];
        int elem = 0;
        int direction = 0;
        int topbound = 0;
        int botbound = n -1;
        int leftbound = 0;
        int rightbound = n - 1;

        while(elem < n*n) {
            if(direction == 0) {
                for(int i = leftbound; i <= rightbound; i++) {
                    elem = elem + 1;
                    smatrix[topbound][i] = elem;
                }
                topbound = topbound + 1;
            } else if(direction == 1) {
                for(int i = topbound; i <= botbound; i++) {
                    elem = elem + 1;
                    smatrix[i][rightbound] = elem;
                }
                rightbound = rightbound - 1;
            } else if(direction == 2) {
                for(int i = rightbound; i >= leftbound; i--) {
                    elem = elem + 1;
                    smatrix[botbound][i] = elem;
                }
                botbound = botbound - 1;
            } else  {
                for(int i = botbound; i >= topbound; i--) {
                    elem = elem + 1;
                    smatrix[i][leftbound] = elem;
                }
                leftbound = leftbound + 1;
            }

            direction = (direction + 1)%4;
        }

        return smatrix;
    }

    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxWater = 0;
        int curWater = 0;

        while(left < right) {
            curWater = Math.min(height[left], height[right])*(right - left);
            if(maxWater < curWater) maxWater = curWater;
            if(height[left] < height[right]) left = left + 1;
            else right = right - 1;
        }
        return maxWater;
    }

    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>();
        dfsParenthesis(result, "", n, n);
        return result;
    }

    public void dfsParenthesis(List<String> result, String s, int left, int right) {
        if(left > right) return;

        if(left == 0 && right == 0) {
            result.add(s);
            return;
        }

        if(left > 0) dfsParenthesis(result, s+"(", left - 1, right);
        if(right > 0) dfsParenthesis(result, s+")", left, right - 1);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<String>();

        if(root == null) return result;

        dfsTreePaths(root, "", result);
        return result;
    }

    public void dfsTreePaths(TreeNode root, String s, List<String> result) {
        if(root.left == null && root.right == null) {
            s = s + root.val;
            result.add(s);
        }

        s = s + root.val;
        s = s + "->";

        if(root.left != null) dfsTreePaths(root.left, s, result);
        if(root.right != null) dfsTreePaths(root.right, s, result);
    }

    public int romanToInt(String s) {
        HashMap<Character, Integer> myTable= new HashMap<Character, Integer>();
        myTable.put('I', 1);
        myTable.put('V', 5);
        myTable.put('X', 10);
        myTable.put('L', 50);
        myTable.put('C', 100);
        myTable.put('D', 500);
        myTable.put('M', 1000);

        int num = 0;
        for(int i = 0; i < s.length()-1; i ++) {
            if(myTable.get(s.charAt(i)) < myTable.get(s.charAt(i+1))) num = num - myTable.get(s.charAt(i));
            else num = num + myTable.get(s.charAt(i));
        }
        return num + myTable.get(s.charAt(s.length()-1));
    }

    public String intToRoman(int num) {
        LinkedHashMap<Integer, String> myTable = new LinkedHashMap<Integer, String>();
        myTable.put(1000, "M");
        myTable.put(900, "CM");
        myTable.put(500, "D");
        myTable.put(400, "CD");
        myTable.put(100, "C");
        myTable.put(90, "XC");
        myTable.put(50, "L");
        myTable.put(40, "XL");
        myTable.put(10, "X");
        myTable.put(9, "IX");
        myTable.put(5, "V");
        myTable.put(4, "IV");
        myTable.put(1, "I");

        String romeNum = "";

        for(int i = 0; i < myTable.size(); i++) {
            int curLim = (int) myTable.keySet().toArray()[i];
            while(num >= curLim) {
                num = num - curLim;
                romeNum = romeNum + myTable.get(curLim);
            }
        }

        return romeNum;
    }


    public void flatten(TreeNode root) {
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode p = root;

        while(p != null || !s.isEmpty()) {
            if(p.right != null) s.push(p.right);

            if(p.left != null) {
                p.right = p.left;
                p.left = null;
            } else if(!s.isEmpty()) {
                TreeNode temp = s.pop();
                p.right = temp;
            }
            p = p.right;
        }
    }

    public TreeNode sortedListToBST(ListNode head) {
        if(head == null) return null;

        int listLen = 0;
        ListNode p = head;
        while(p != null) {
            listLen++;
            p = p.next;
        }

        int[] myArray = new int[listLen];
        p = head;
        for(int i = 0; i < listLen; i++) {
            myArray[i] = p.val;
            p = p.next;
        }

        return sortedArrayToBST(myArray, 0, listLen-1);

    }

    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        if(root.left == null) return minDepth(root.right) + 1;
        if(root.right == null) return  minDepth(root.left) + 1;

        return  Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }

    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

    public int rob(int[] nums) {
        int odd = 0;
        int even = 0;
        for(int i = 0; i < nums.length; i++) {
            if(i%2 == 1) odd = Math.max(nums[i] + odd, even);
            else even = Math.max(nums[i] + even, odd);
        }
        return Math.max(odd, even);
    }

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int idxA = m - 1;
        int idxB = n - 1;
        int idxM = m + n - 1;
        while(idxA >= 0 && idxB >= 0) {
            if(nums1[idxA] > nums2[idxB]) nums1[idxM--] = nums1[idxA--];
            else nums1[idxM--] = nums2[idxB--];
        }
        while(idxB >= 0) nums1[idxM--] = nums2[idxB--];
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode p1 = l1;
        ListNode p2 = l2;
        ListNode fake = new ListNode(0);
        ListNode p = fake;

        while(p1 != null && p2 != null) {
            if(p1.val < p2.val) {
                p.next = p1;
                p1 = p1.next;
            } else {
                p.next = p2;
                p2 = p2.next;
            }
            p = p.next;
        }
        if(p1 != null) p.next = p1;
        if(p2 != null) p.next = p2;

        return fake.next;
    }

    public ListNode mergeSort(ListNode[] l, int start, int end) {
        while(start < end) {
            int mid = (start + end)/2;
            ListNode leftList = mergeSort(l, start, mid);
            ListNode rightList = mergeSort(l, mid+1, end);
            return mergeTwoLists(leftList, rightList);
        }
        return l[start];
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0) return null;
        return mergeSort(lists, 0, lists.length-1);
    }

    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode fast = head;
        ListNode slow = head;
        ListNode firstHalf = head;
        while(fast.next != null && fast.next.next !=null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode secondHalf = slow.next;
        slow.next = null;
        ListNode leftSorted = null;
        ListNode rightSorted = null;
        if(firstHalf != secondHalf) {
            leftSorted = sortList(firstHalf);
            rightSorted = sortList(secondHalf);
        }
        return mergeTwoLists(leftSorted, rightSorted);
    }

    public int sumNumbers(TreeNode root) {
        return treeLeafSum(root, 0);
    }

    public int treeLeafSum(TreeNode root, int levelBase) {
        if(root == null) return 0;

        if(root.left == null && root.right == null) return levelBase + root.val;

        int nextBase = (levelBase + root.val)*10;
        int rightSum = treeLeafSum(root.right, nextBase);
        int leftSum = treeLeafSum(root.left, nextBase);

        return rightSum+leftSum;
    }

    public int removeDuplicates(int[] nums) {
        if(nums.length <= 2) return nums.length;

        int pre = 1;
        int cur = 2;
        while(cur < nums.length) {
            if(nums[cur] == nums[pre] && nums[cur] == nums[pre - 1]) cur++;
            else {
                pre++;
                nums[pre] = nums[cur];
                cur++;
            }
        }

        return pre+1;
    }

    public ListNode deleteDuplicates(ListNode head) {
        ListNode t = new ListNode(0);
        t.next = head;
        ListNode p = t;
        while(p.next != null && p.next.next != null) {
            if(p.next.val == p.next.next.val) {
                int dup = p.next.val;
                while(p.next != null && p.next.val == dup) p.next = p.next.next;
            } else p = p.next;
        }
        return t.next;
    }

    public RandomListNode copyRandomList(RandomListNode head) {
        if(head == null) return null;

        HashMap<RandomListNode, RandomListNode> mymap = new HashMap<RandomListNode, RandomListNode>();
        RandomListNode newHead = new RandomListNode(head.label);

        RandomListNode p = head;
        RandomListNode q = newHead;


        mymap.put(p, q);

        p = p.next;
        while(p != null) {
            RandomListNode temp = new RandomListNode(p.label);
            mymap.put(p, temp);
            q.next = temp;
            q = q.next;
            p = p.next;
        }

        p = head;
        q = newHead;
        while(p != null) {
            if(p.random != null) q.random = mymap.get(p.random);
            else q.random = null;
            p = p.next;
            q = q.next;
        }
        return newHead;
    }

    public int hIndex(int[] citations) {
        int N = citations.length;
        int[] cnts = new int[N+1];

        for(int i : citations) {
            if(i >= N) cnts[N] = cnts[N] + 1;
            else cnts[i] = cnts[i] + 1;
        }

        int sum = 0;

        for(int j = N; j >= 0; j--) {
            if(sum + cnts[j] >= j) return j;
            sum = sum + cnts[j];
        }
        return 0;
    }

    public int hIndexII(int[] citations) {
        if(citations == null || citations.length == 0) return 0;
        int N = citations.length;
        int low = 0;
        int high = N-1;
        int mid = 0;
        while(low <= high) {
            mid = (low + high)/2;
            if(N - mid > citations[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return N - low;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int numRows = matrix.length;
        int numCols = matrix[0].length;

        int i = 0;
        int j = numCols - 1;

        while(i < numRows && j >= 0) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }

    public String convert(String s, int numRows) {
        if(numRows == 1) return s;

        String result = "";
        int direction = 1;
        String[] flag = new String[numRows];
        for(int i = 0; i < numRows; i++) flag[i] = "";
        int i = 0;
        for(int k = 0; k < s.length(); k++) {
            flag[i] += s.charAt(k);
            if((i == 0 && k != 0) || (i == numRows -1)) direction = - direction;
            i = i + direction;
        }

        for(int j = 0; j < numRows; j++) {
            result += flag[j];
        }

        return result;

    }

    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        while(x/div >= 10) div = div*10;
        int left;
        int right;
        while(x > 0) {
            left = x/div;
            right = x%10;
            if(left != right) return false;

            x = (x%div)/10;
            div = div/100;
        }
        return true;
    }

    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return false;
        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode secondHead = slow.next;

        ListNode p1 = secondHead;
        ListNode p2 = secondHead.next;
        secondHead.next = null;

        while (p1 != null && p2 != null) {
            ListNode temp = p2.next;
            p2.next = p1;
            p1 = p2;
            if(temp != null) p2 = temp;
            else break;
        }

        ListNode q = head;
        while (p1 != null) {
            if(p1.val != q.val) return false;
            p1 = p1.next;
            q = q.next;
        }
        return true;
    }

    public int missingNumber(int[] nums) {
        int sum = 0;
        for(int i : nums) {
            sum += i;
        }
        int n = nums.length;
        return (n+1)*n/2 - sum;
    }

    public boolean isValidSudoku(char[][] board) {
        if(board == null || board.length != 9 || board[0].length != 9) return false;

        HashSet<Character> mySet = new HashSet<Character>();
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(mySet.contains(board[i][j])) return false;
                mySet.add(board[i][j]);
            }
            mySet.clear();
        }

        for(int j = 0; j < 9; j++) {
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                if(mySet.contains(board[i][j])) return false;
                mySet.add(board[i][j]);
            }
            mySet.clear();
        }

        for(int k = 0; k < 9; k++) {
            for(int i = k/3*3; i < k/3*3+3; i++) {
                for(int j = (k%3)*3; j < (k%3)*3+3; j++) {
                    if(board[i][j] == '.') continue;
                    if(mySet.contains(board[i][j])) return false;
                    mySet.add(board[i][j]);
                }
            }
            mySet.clear();
        }

        return true;
    }

    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0) return "";

        int minLen = Integer.MAX_VALUE;
        for(int i = 0; i < strs.length; i++) {
            if(strs[i].length() < minLen) minLen = strs[i].length();
        }

        if(minLen == 0) return "";

        String commonPrefix = "";
        int i = 0;

        while(i < minLen) {
            for(int j = 1 ; j < strs.length; j++) {
                if(strs[j].charAt(i) != strs[0].charAt(i)) return commonPrefix;
            }
            commonPrefix = commonPrefix + strs[0].charAt(i);
        }

        return commonPrefix;
    }


    public static void main(String[] args) {
        int num = 3;
        int[][] matrix = new int[][]{{1, 2,3}, {4, 5,6}, {7,8,9}};
        int[][] smatrix = new int[num][num];

        Solution mysol = new Solution();

        List<Integer> result = mysol.spiralOrder(matrix);
        System.out.println(mysol.intToRoman(3999));


        ListNode myList = null;
        ListNode testList = new ListNode(2);
        testList.next = new ListNode(1);
        myList = mysol.sortList(testList);

    }
}
