#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <climits>
#include <functional>
#include <stdint.h>
#include <unordered_set>
#include <bitset>


#include "Trie.h"

using std::vector;
using std::string;
using std::set;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::queue;
using std::stack;
using std::max;
using std::min;
using std::bitset;


class Trie;
class TrieNode;

#ifndef ANSWER_H
#define ANSWER_H


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct GraphNode {
	string destination;
	double distance;
	GraphNode(string dest, double dist) : destination(dest), distance(dist) {}
};


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	/*
	Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
	For example:
	Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
	*/
	int addDigits(int num) {
		int result = 1 + ((num - 1) % 9);
		return result;
	}

	/*
	Given a binary tree, find its maximum depth.
	The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
	*/
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return std::max(leftDepth, rightDepth) + 1;
	}

	/*
	Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
	Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
	*/
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
		return;
	}

	/*
	Given two binary trees, write a function to check if they are equal or not.
	Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
	*/
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) return true;
		else if (q && p && p->val == q->val) return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		else return false;
	}

	/*
	Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
	For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
	*/
	void moveZeroes(vector<int>& nums) {
		size_t i = 0;
		size_t j = 0;
		while (j < nums.size()) {
			if (nums[j] != 0) {
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				i++;
			}
			j++;
		}
		return;
	}

	//Invert a binary tree.
	TreeNode* invertTree(TreeNode* root) {
		if (root) {
			TreeNode *temp = root->left;
			root->left = root->right;
			root->right = temp;

			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}

	/*
	Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
	According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).
	*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
		else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
		else return root;
	}

	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n) {
			n = n&(n - 1);
			count++;
		}
		return count;
	}

	/*
	Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
	*/
	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		for (int i : nums) {
			if (s.find(i) == s.end()) s.insert(i);
			else return true;
		}
		return false;
	}

	//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
	int titleToNumber(string s) {
		int number = 0;
		for (size_t i = 0; i < s.size(); i++) {
			char c = s.at(i);
			int current_number = static_cast<int> (c - 'A') + 1;
			number = number * 26 + current_number;
		}
		return number;
	}

	/*
	Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
	You may assume that the array is non-empty and the majority element always exist in the array.
	*/
	int majorityElement(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

	/*
	Given two strings s and t, write a function to determine if t is an anagram of s.
	For example,
	s = "anagram", t = "nagaram", return true.
	s = "rat", t = "car", return false.
	*/
	bool isAnagram(string s, string t) {
		size_t lenS = s.length();
		size_t lenT = t.length();
		if (lenT == 0) return false;
		if (lenS != lenT) return false;

		vector<int> count(26, 0);
		for (size_t i = 0; i < lenS; i++) {
			count[s[i] - 'a']++;
		}

		for (size_t i = 0; i < lenT; i++) {
			if (--count[t[i] - 'a'] < 0) return false;

		}
		return true;
	}

	//Given an array of strings, group anagrams together.
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> anagramMap;
		for (string str : strs) {
			string temp = str;
			sort(temp.begin(), temp.end());
			if (anagramMap.find(temp) != anagramMap.end()) {
				anagramMap[temp].push_back(str);
			}
			else {
				anagramMap.emplace(temp, vector<string>(1, str));
			}
		}
		for (auto anagramGroup : anagramMap) {
			result.push_back(anagramGroup.second);
		}
		return result;
	}

	/*
	Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
	Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
	The order of output does not matter.
	*/
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		vector<int> charMap(256, 0);
		for (char c : p) {
			charMap[c]++;
		}


		int left = 0;
		int right = 0;
		int count = static_cast<int>(p.size());
		while (right < static_cast<int>(s.size())) {
			if (charMap[s[right]] >= 1) {
				count--;
			}
			charMap[s[right]]--;
			right++;

			if (count == 0) result.push_back(left);

			if (right - left == static_cast<int>(p.size())) {
				if (charMap[s[left]] >= 0) {
					count++;
				}
				charMap[s[left]]++;
				left++;
			}
		}
		return result;
	}

	/*
	Given a roman numeral, convert it to an integer.
	Input is guaranteed to be within the range from 1 to 3999.
	*/
	int romanToInt(string s) {
		int val[255];
		val[static_cast<int>('I')] = 1;
		val[static_cast<int>('V')] = 5;
		val[static_cast<int>('X')] = 10;
		val[static_cast<int>('L')] = 50;
		val[static_cast<int>('C')] = 100;
		val[static_cast<int>('D')] = 500;
		val[static_cast<int>('M')] = 1000;

		int num = 0;
		for (size_t i = 0; i < s.length() - 1; i++) {
			if (val[static_cast<int>(s[i])] < val[static_cast<int>(s[i + 1])]) num = num - val[static_cast<int>(s[i])];
			else num += val[static_cast<int>(s[i])];
		}
		return num + val[static_cast<int>(s[s.length() - 1])];
	}

	/*
	Given a sorted linked list, delete all duplicates such that each element appear only once.
	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *cur = head;
		while (cur && cur->next) {
			if (cur->val == cur->next->val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}

	/*
	You are climbing a stair case. It takes n steps to reach to the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
	*/
	int climbStairs(int n) {
		if (n == 0 || n == 1 || n == 2) return n;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i < n + 1; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	//Reverse a singly linked list.
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = NULL;
		while (head) {
			ListNode *temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}
		return pre;
	}

	/*
	Write a program to check whether a given number is an ugly number.
	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
	*/
	bool isUgly(int num) {
		if (num <= 0) return false;
		int factor[] = { 2, 3,5 };
		for (int x : factor) {
			while (num%x == 0) num = num / x;
		}
		return num == 1;
	}

	/*
	Write an algorithm to determine if a number is "happy".
	A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
	*/
	bool isHappy(int n) {
		set<int> showedNumbers;
		int sum = n;
		while (sum != 1) {
			n = sum;
			sum = 0;
			while (n > 0) {
				sum += (n % 10)*(n % 10);
				n = n / 10;
			}
			if (showedNumbers.find(sum) != showedNumbers.end()) return false;
			else showedNumbers.insert(sum);
		}
		return true;
	}

	bool canWinNim(int n) {
		return n % 4 != 0;
	}

	//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *result = new ListNode(0);
		ListNode *current = result;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				current->next = l1;
				l1 = l1->next;
			}
			else {
				current->next = l2;
				l2 = l2->next;
			}
			current = current->next;
		}
		if (l1) {
			current->next = l1;
		}
		if (l2) {
			current->next = l2;
		}
		return result->next;
	}

	//Merge k Sorted Lists
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = static_cast<int>(lists.size());
		if (len < 1) return NULL;
		ListNode* result = lists[0];
		for (int i = 1; i < len; i++) {
			result = mergeTwoLists(result, lists[i]);
		}
		return result;
	}

	/*
	Given a binary tree, determine if it is height-balanced.
	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
	*/
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (std::abs(treeDepth(root->left) - treeDepth(root->right)) > 1) {
			return false;
		}
		return (isBalanced(root->left) && isBalanced(root->right));
	}

	int treeDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + std::max(treeDepth(root->left), treeDepth(root->right));
	}

	//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) {
			return true;
		}
		else if (p == NULL || q == NULL) {
			return false;
		}
		return (p->val == q->val && isSymmetric(p->right, q->left) && isSymmetric(p->left, q->right));
	}
	/*
	Given an array and a value, remove all instances of that value in place and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
	*/
	int removeElement(vector<int>& nums, int val) {
		size_t i = 0;
		int j = 0;
		auto k = nums.size();
		while (i < nums.size()) {
			if (nums[i] == val) {
				auto temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				j++;
			}
			i++;
		}
		nums.erase(nums.begin(), nums.begin() + j);
		return static_cast<int>(k - j);
	}

	//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		queue<TreeNode*> treeNodeQueue;
		queue<TreeNode*> nextTreeNodeQueue;
		vector<int> cur;

		treeNodeQueue.push(root);
		while (!treeNodeQueue.empty()) {
			TreeNode* tempNode = treeNodeQueue.front();
			treeNodeQueue.pop();
			cur.push_back(tempNode->val);

			if (tempNode->left) nextTreeNodeQueue.push(tempNode->left);
			if (tempNode->right) nextTreeNodeQueue.push(tempNode->right);

			if (treeNodeQueue.empty()) {
				treeNodeQueue = nextTreeNodeQueue;
				nextTreeNodeQueue = queue<TreeNode*>();
				result.push_back(cur);
				cur.clear();
			}
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	/*
	Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	*/
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		size_t i = 0;
		int j = 0;
		//auto k = nums.size();
		while (i < nums.size()) {
			if (nums[i] != nums[j]) {
				auto temp = nums[j + 1];
				nums[j + 1] = nums[i];
				nums[i] = temp;
				j++;
			}
			i++;
		}
		return j + 1;
	}

	//Given an integer, write a function to determine if it is a power of two.
	bool isPowerOfTwo(int n) {
		int cnt = 0;
		while (n > 0) {
			cnt += (n & 1);
			n = n >> 1;
		}
		return cnt == 1;
	}

	/*
	You are a professional robber planning to rob houses along a street.
	Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
	and it will automatically contact the police if two adjacent houses were broken into on the same night.
	Given a list of non-negative integers representing the amount of money of each house,
	determine the maximum amount of money you can rob tonight without alerting the police.
	*/
	int rob(vector<int>& nums) {
		int odd = 0;
		int even = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (i % 2 == 1) odd = std::max(odd + nums[i], even);
			else even = std::max(even + nums[i], odd);
		}
		return std::max(odd, even);
	}


	/*
	The thief has found himself a new place for his thievery again. 
	There is only one entrance to this area, called the "root." 
	Besides the root, each house has one and only one parent house. 
	After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
	It will automatically contact the police if two directly-linked houses were broken into on the same night.
	Determine the maximum amount of money the thief can rob tonight without alerting the police.
	*/
	int rob(TreeNode* root) {
		return dfsRob(root).first;
	}

	/*
	rob_root = max(rob_L + rob_R , no_rob_L + no_nob_R + root.val)
	no_rob_root = rob_L + rob_R
	first means rob current node
	second means not rob current node
	*/
	pair<int, int> dfsRob(TreeNode* root) {
		pair<int, int> dp = make_pair(0, 0);
		if(root) {
			pair<int, int> rob_left = dfsRob(root->left);
			pair<int, int> rob_right = dfsRob(root->right);
			dp.second = rob_left.first + rob_right.first;
			dp.first = max(dp.second, rob_left.second + rob_right.second + root->val);
		}
		return dp;
	}

	/*
	Given a non-negative number represented as an array of digits, plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.
	*/
	vector<int> plusOne(vector<int>& digits) {
		int addone = 1;
		for (int i = static_cast<int>(digits.size()) - 1; i >= 0; i--) {
			int currentDigit = (digits[i] + addone) % 10;
			addone = (digits[i] + addone) / 10;
			digits[i] = currentDigit;
			if (addone == 0) return digits;
		}
		vector<int> result = vector<int>(digits.size() + 1, 0);
		result[0] = 1;
		return result;
	}

	/*
	Given numRows, generate the first numRows of Pascal's triangle.
	[
	[1],
	[1,1],
	[1,2,1],
	[1,3,3,1],
	[1,4,6,4,1]
	]
	*/
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result = vector<vector<int>>();
		if (numRows <= 0) return result;

		vector<int> pre = vector<int>();
		pre.push_back(1);
		result.push_back(pre);

		for (int i = 1; i < numRows; i++) {
			vector<int> cur = vector<int>();
			cur.push_back(1);

			for (size_t j = 0; j < pre.size() - 1; j++) {
				cur.push_back(pre[j] + pre[j + 1]);
			}

			cur.push_back(1);
			result.push_back(cur);
			pre = cur;
		}
		return result;
	}

	//Given an integer n, return the number of trailing zeroes in n!.
	int trailingZeroes(int n) {
		int i = 1;
		int zeros = 0;

		while (n / std::pow(5, 1) >= 1) {
			zeros = static_cast<int>(zeros + n / std::pow(5, 1));
			i++;
		}
		return zeros;
	}

	/*
	Given an index k, return the kth row of the Pascal's triangle.
	For example, given k = 3,
	Return [1,3,3,1].
	*/
	vector<int> getRow(int rowIndex) {
		vector<int> result = vector<int>();
		if (rowIndex < 0) return result;
		result = vector<int>(rowIndex + 1, 1);
		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i - 1; j > 0; j--) {
				result[j] = result[j] + result[j - 1];
			}
		}
		return result;
	}

	//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level from root to leaf).
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		queue<TreeNode*> treeNodeQueue;
		queue<TreeNode*> nextTreeNodeQueue;
		vector<int> cur;

		treeNodeQueue.push(root);
		while (!treeNodeQueue.empty()) {
			TreeNode* tempNode = treeNodeQueue.front();
			treeNodeQueue.pop();
			cur.push_back(tempNode->val);

			if (tempNode->left) nextTreeNodeQueue.push(tempNode->left);
			if (tempNode->right) nextTreeNodeQueue.push(tempNode->right);

			if (treeNodeQueue.empty()) {
				treeNodeQueue = nextTreeNodeQueue;
				nextTreeNodeQueue = queue<TreeNode*>();
				result.push_back(cur);
				cur.clear();
			}
		}
		return result;
	}

	//Determine whether an integer is a palindrome. Do this without extra space.
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int div = 1;
		while (x / div >= 10) div = div * 10;
		int left = 0;
		int right = 0;
		while (x > 0) {
			left = x / div;
			right = x % 10;
			if (right != left) return false;

			x = (x%div) / 10;
			div = div / 100;
		}
		return true;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		ListNode* pa = headA;
		ListNode* pb = headB;

		ListNode* tailA = NULL;
		ListNode* tailB = NULL;

		while (true) {
			if (!pa) pa = headB;
			if (!pb) pb = headA;

			if (!(pa->next)) tailA = pa;
			if (!(pb->next)) tailB = pb;

			if (tailA && tailB && tailA != tailB) return NULL;
			if (pa == pb) return pa;

			pa = pa->next;
			pb = pb->next;
		}
	}

	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;

		return std::min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int idxA = m - 1;
		int idxB = n - 1;
		int idxM = m + n - 1;
		while (idxA >= 0 && idxB >= 0) {
			if (nums1[idxA] > nums2[idxB]) nums1[idxM--] = nums1[idxA--];
			else nums1[idxM--] = nums2[idxB--];
		}

		while (idxB >= 0) nums1[idxM--] = nums2[idxB--];
		return;
	}

	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left && !root->right && sum - root->val == 0) return true;
		return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
	}

	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for (int i = 0; i < 32; i++) {
			if ((n & 1) == 1) res = (res << 1) + 1;
			else res = res << 1;
			n = n >> 1;
		}
		return res;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9 || board[0].size() != 9) return false;

		set<char> mySet = set<char>();

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				if (mySet.find(board[i][j]) != mySet.end()) return false;
				mySet.insert(board[i][j]);
			}
			mySet.clear();
		}

		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.') continue;
				if (mySet.find(board[i][j]) != mySet.end()) return false;
				mySet.insert(board[i][j]);
			}
			mySet.clear();
		}

		for (int k = 0; k < 9; k++) {
			for (int i = k / 3 * 3; i < k / 3 * 3 + 3; i++) {
				for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++) {
					if (board[i][j] == '.') continue;
					if (mySet.find(board[i][j]) != mySet.end()) return false;
					mySet.insert(board[i][j]);
				}
			}
			mySet.clear();
		}
		return true;
	}

	int lengthOfLastWord(string s) {
		if (s.size() < 1) return 0;
		int result = 0;
		for (auto iter = s.end() - 1; iter >= s.begin(); iter--) {
			if (*iter != ' ') result++;
			else if (result > 0) return result;
		}
		return result;
	}

	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		if (C < E || G < A) return (G - E)*(H - F) + (C - A)*(D - B);
		if (D < F || H < B) return (G - E)*(H - F) + (C - A)*(D - B);

		int right = std::min(C, G);
		int left = std::max(A, E);
		int top = std::min(H, D);
		int bottom = std::max(F, B);

		return (G - E)*(H - F) + (C - A)*(D - B) - (right - left)*(top - bottom);
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head || !head->next) return NULL;


		ListNode* fast = head;
		ListNode* slow = head;

		for (int i = 0; i < n; i++) fast = fast->next;

		if (!fast) {
			return head->next;
		}
		else {
			while (fast->next) {
				fast = fast->next;
				slow = slow->next;
			}
		}

		slow->next = slow->next->next;

		return head;
	}

	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> myMap;
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			if (myMap.find(nums[i]) == myMap.end()) {
				myMap[nums[i]] = i;
			}
			else {
				if (static_cast<int>(i - myMap[nums[i]]) <= k) return true;
				else myMap[nums[i]] = i;
			}
		}
		return false;
	}

	bool isValid(string s) {
		stack<char> st = stack<char>();
		for (size_t i = 0; i < s.size(); i++) {
			if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
				st.push(s[i]);
			}
			else {
				if (st.empty()) return false;
				if ((s[i] == ')') && (st.top() != '(')) return false;
				if ((s[i] == ']') && (st.top() != '[')) return false;
				if ((s[i] == '}') && (st.top() != '{')) return false;
				st.pop();
			}
		}
		return st.empty();
	}

	bool isIsomorphic(string s, string t) {
		map<char, char> myMap = map<char, char>();
		set<char> mySet = set<char>();
		for (size_t i = 0; i < s.size(); i++) {
			if (myMap.find(s[i]) != myMap.end()) {
				if (myMap[s[i]] == t[i]) continue;
				else return false;
			}
			else {
				if (mySet.find(t[i]) == mySet.end()) {
					mySet.insert(t[i]);
					myMap[s[i]] = t[i];
				}
				else {
					return false;
				}
			}
		}
		return true;
	}

	bool wordPattern(string pattern, string str) {
		std::istringstream iss(str);
		unordered_map<char, string> myMap = unordered_map<char, string>();
		int i = 0;
		for (string word; iss >> word; i++) {
			if (myMap.find(pattern[i]) != myMap.end()) {
				if (myMap[pattern[i]] != word) return false;
			}
			else {
				for (unordered_map<char, string>::iterator iter = myMap.begin(); iter != myMap.end(); iter++) {
					if (iter->second == word) return false;
				}
				myMap[pattern[i]] = word;
			}
		}
		return i == static_cast<int>(pattern.size());
	}

	string cas(string str) {
		string str1;
		int str_cnt = 1;
		char chr = str[0];

		for (size_t i = 1; i <= str.size(); i++) {
			if (chr == str[i]) str_cnt++;
			else {
				char temp = '0' + str_cnt;
				str1 = str1 + temp;
				str1 = str1 + chr;
				chr = str[i];
				str_cnt = 1;
			}
		}
		return str1;
	}

	string countAndSay(int n) {
		if (n == 1) return "1";
		string str = "1";
		string str_read;
		for (int i = 1; i < n; i++) {
			str_read = cas(str);
			str = str_read;
		}
		return str_read;
	}

	string addBinary(string a, string b) {
		if (a.size() == 0) return b;
		if (b.size() == 0) return a;

		int pa = static_cast<int>(a.size()) - 1;
		int pb = static_cast<int>(b.size()) - 1;
		int carry = 0;
		string result = "";

		while (pa >= 0 && pb >= 0) {
			int digit = static_cast<int> (a[pa] - '0' + b[pb] - '0') + carry;
			carry = digit / 2;
			digit = digit % 2;
			result = std::to_string(digit) + result;
			pa--;
			pb--;
		}

		while (pa >= 0) {
			int digit = static_cast<int> (a[pa] - '0') + carry;
			carry = digit / 2;
			digit = digit % 2;
			result = std::to_string(digit) + result;
			pa--;
		}

		while (pb >= 0) {
			int digit = static_cast<int> (b[pb] - '0') + carry;
			carry = digit / 2;
			digit = digit % 2;
			result = std::to_string(digit) + result;
			pb--;
		}

		if (carry > 0) result = std::to_string(carry) + result;
		return result;
	}

	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];

		for (size_t i = 0; i < strs[0].size(); i++) {
			for (size_t j = 1; j < strs.size(); j++) {
				if (i > strs[j].size() || strs[j - 1][i] != strs[j][i]) {
					return strs[j].substr(0, i);
				}
			}
		}

		return strs[0];

	}

	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode *slow = head, *fast = head;
		stack<int> s;
		s.push(head->val);

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			s.push(slow->val);
		}

		if (!fast->next) s.pop();

		while (slow->next) {
			slow = slow->next;
			int temp = s.top();
			s.pop();
			if (temp != slow->val) return false;
		}

		return true;
	}

	string getHint(string secret, string guess) {
		vector<int> m = vector<int>(256, 0);
		int bull = 0;
		int cow = 0;

		for (size_t i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i]) bull++;
			else {
				if (m[secret[i]]++ < 0) cow++;
				if (m[guess[i]]-- > 0) cow++;
			}
		}

		return std::to_string(bull) + "A" + std::to_string(cow) + "B";
	}

	//Given a binary tree, return all root-to-leaf paths.
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result = vector<string>();
		if (!root) return result;

		string s = "";
		dfsBinaryTreePath(root, s, result);

		return result;
	}

	void dfsBinaryTreePath(TreeNode* root, string s, vector<string>& result) {
		if (!root->left && !root->right) {
			s = s + std::to_string(root->val);
			result.push_back(s);
		}

		s = s + std::to_string(root->val);
		s = s + "->";

		if (root->left) dfsBinaryTreePath(root->left, s, result);
		if (root->right) dfsBinaryTreePath(root->right, s, result);
	}

	int reverse(int x) {
		long rev = 0;
		while (x != 0)
		{
			rev = rev * 10 + x % 10;
			x = x / 10;
		}

		if (rev > std::pow(2, 31) - 1 || rev < -std::pow(2, 31)) return 0;
		else return static_cast<int>(rev);

	}

	int strStr(string haystack, string needle) {
		int n = static_cast<int>(needle.size());
		if (n == 0) return 0;
		int m = static_cast<int>(haystack.size());
		if (m == 0) return -1;

		for (int i = 0; i <= m - n; i++) {
			for (int j = 0; j < n; j++) {
				char c1 = haystack[i + j];
				char c2 = needle[j];

				if (c1 == c2 && j == n - 1) return i;
				if (c1 != c2) break;
			}
		}
		return -1;
	}

	

	bool isPalindrome(string s) {
		int len = static_cast<int>(s.size());
		if (len <= 1) return true;
		int i = 0;
		int j = len - 1;
		while (i <= j) {
			if (!isAlphanumeric(s[i])) i++;
			else if (!isAlphanumeric(s[j])) j--;
			else if (isSameChar(s[i], s[j])) {
				i++;
				j--;
			}
			else return false;
		}
		return true;
	}

	bool isAlphanumeric(char c) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isSameChar(char a, char b) {
		return toupper(a) == toupper(b);
	}


	/*
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s.
	*/
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		if(s.empty()) return result;
		
		vector<string> onePartition;
		dfsPartition(s, 0, result, onePartition);
		return result;
	}

	void dfsPartition(string s, int start, vector<vector<string>>& result, vector<string>& onePartition) {
		// stop condition
		if(start == static_cast<int>(s.size())) {
			result.push_back(onePartition);
			return;
		}

		//dfs search
		for(int len = 1; len + start <= static_cast<int>(s.size()); len++) {
			string temp = s.substr(start, len);
			if(isPalindrome(temp)) {
				onePartition.push_back(temp);
				dfsPartition(s, start+len, result, onePartition);
				onePartition.pop_back();
			}
		}
	}

	/*
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return the minimum cuts needed for a palindrome partitioning of s.
	For example, given s = "aab",
	Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
	*/
	int minCut(string s) {
		int len = static_cast<int>(s.size());
		if (len <= 1) return 0;
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		vector<int> cut(len, INT_MAX);
		
		for (int right = 0; right < len; right++) {
			for (int left = 0; left <= right; left++) {
				if (s[left] == s[right] && (right - left <= 1 || dp[left + 1][right - 1])) {
					dp[left][right] = true;
					
					if (left > 0) {
						cut[right] = min(cut[right], cut[left - 1] + 1);
					}
					else {
						cut[right] = 0;
					}
				}
			}
		}

		return cut.back();
	}

	/*
	Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
	so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
	*/
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> result;
		map<string, int> myMap;
		set<int> mySet;

		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			myMap[words[i]] = i;
			mySet.insert(static_cast<int>(words[i].size()));
		}

		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			string part = string(words[i].rbegin(), words[i].rend());
			if (myMap.count(part) && myMap[part] != i) {
				vector<int> onePair;
				onePair.push_back(i);
				onePair.push_back(myMap[part]);
				result.push_back(onePair);
			}

			int len = static_cast<int>(part.size());
			auto lenLim = mySet.find(len);
			for (set<int>::iterator it = mySet.begin(); it != lenLim; it++) {
				int counterpartLen = *it;
				if (isPartPalindrome(part, 0, len - counterpartLen - 1) && myMap.count(part.substr(len - counterpartLen, string::npos))) {
					vector<int> onePair;
					onePair.push_back(i);
					onePair.push_back(myMap[part.substr(len - counterpartLen, string::npos)]);
					result.push_back(onePair);
				}
				
				if (isPartPalindrome(part, counterpartLen, len - 1) && myMap.count(part.substr(0, counterpartLen))) {
					vector<int> onePair;
					onePair.push_back(myMap[part.substr(0, counterpartLen)]);
					onePair.push_back(i);
					result.push_back(onePair);
				}
				
			}
		}
		return result;
	}

	bool isPartPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] == s[right]) {
				left++;
				right--;
			}
			else {
				return false;
			}
		}
		return true;
	}

	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		string result = "";
		vector<string> flag = vector<string>(numRows, "");
		int direction = 1;
		int i = 0;
		for (size_t k = 0; k < s.size(); k++) {
			flag[i] = flag[i] + s[k];
			if ((i == 0 && k != 0) || (i == numRows - 1)) direction = -direction;
			i = i + direction;
		}

		for (int j = 0; j < numRows; j++) {
			result = result + flag[j];
		}

		return result;
	}

	int countPrimes(int n) {
		if (n < 2) return 0;

		vector<bool> flag = vector<bool>(n, true);
		flag[0] = false;
		flag[1] = false;
		int i = 2;
		while (i*i < n) {
			if (flag[i]) {
				int j = i + i;
				while (j < n) {
					flag[j] = false;
					j = j + i;
				}
			}
			i = i + 1;
		}

		int count = 0;
		for (bool f : flag) {
			if (f) count++;
		}
		return count;
	}

	/*
	Given a sorted integer array without duplicates, return the summary of its ranges.
	For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
	*/
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result = vector<string>();
		if (nums.empty()) return result;
		string s;
		int start = nums[0];
		int end = nums[0];
		for (size_t i = 1; i <= nums.size(); i++) {
			if ((i < nums.size()) && (nums[i] == end + 1)) {
				end = nums[i];
			}
			else {
				if (start == end) s = std::to_string(start);
				else s = std::to_string(start) + "->" + std::to_string(end);
				result.push_back(s);

				if (i < nums.size()) {
					start = nums[i];
					end = nums[i];
				}
			}
		}
		return result;
	}

	string convertToTitle(int n) {
		string result;
		while (n > 0) {
			char current = static_cast<char>('A' + (n - 1) % 26);
			result = current + result;
			n = (n - 1) / 26;
		}
		return result;
	}

	void rotate(vector<int>& nums, int k) {
		int length = static_cast<int>(nums.size());
		k = k%length;
		reverseNum(nums, 0, length - k);
		reverseNum(nums, length - k, length);
		reverseNum(nums, 0, length);
	}

	void reverseNum(vector<int>& nums, int start, int end) {
		for (int i = start; i < (start + end) / 2; i++) {
			int temp = nums[i];
			nums[i] = nums[end + start - 1 - i];
			nums[end + start - 1 - i] = temp;
		}
	}

	int myAtoi(string str) {
		return static_cast<int>(str.length());
	}

	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int num : nums) {
			result = result^num;
		}
		return result;
	}

	vector<int> singleNumberIII(vector<int>& nums) {
		int AxorB = 0;
		for (int num : nums) {
			AxorB = AxorB^num;
		}

		int lastBit = AxorB&(~(AxorB - 1));
		int A = 0;
		int B = 0;
		for (int num : nums) {
			if (lastBit&num) A = A^num;
			else B = B^num;
		}

		vector<int> result = vector<int>(A, B);
		return result;
	}

	int maxProfitII(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		int profit = 0;
		for (size_t i = 0; i < prices.size() - 1; i++) {
			if (prices[i + 1] - prices[i] > 0) profit = profit + prices[i + 1] - prices[i];
		}
		return profit;
	}

	vector<int> productExceptSelf(vector<int>& nums) {
		int len = static_cast<int>(nums.size());
		vector<int> left = vector<int>(len, 0);
		vector<int> right = vector<int>(len, 0);
		vector<int> result = vector<int>(len, 0);

		left[0] = 1;
		right[len - 1] = 1;
		for (int i = 0; i < len - 1; i++) {
			left[i + 1] = nums[i] * left[i];
			right[len - 2 - i] = nums[len - 1 - i] * right[len - 1 - i];
		}

		for (int i = 0; i < len; i++) result[i] = left[i] * right[i];
		return result;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result = vector<int>();
		recursivePreorder(root, result);
		return result;
	}

	void recursivePreorder(TreeNode* root, vector<int>& l) {
		if (root) {
			l.push_back(root->val);
			recursivePreorder(root->left, l);
			recursivePreorder(root->right, l);
		}
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result = vector<int>();
		recursiveInorder(root, result);
		return result;
	}

	void recursiveInorder(TreeNode* root, vector<int>& l) {
		if (root) {
			recursiveInorder(root->left, l);
			l.push_back(root->val);
			recursiveInorder(root->right, l);
		}
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result = vector<int>();
		recursivePostorder(root, result);
		return result;
	}

	void recursivePostorder(TreeNode* root, vector<int>& l) {
		if (root) {
			recursivePostorder(root->left, l);
			recursivePostorder(root->right, l);
			l.push_back(root->val);
		}
	}

	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (int num : nums) {
			sum = sum + num;
		}

		int n = static_cast<int>(nums.size());
		return (n + 1)*n / 2 - sum;
	}

	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (fast == slow) return true;
		}
		return false;
	}

	void connect(TreeLinkNode *root) {
		if (!root) return;
		if (root->left) root->left->next = root->right;
		if (root->right && root->next) root->right->next = root->next->left;

		connect(root->left);
		connect(root->right);
	}

	int searchInsert(vector<int>& nums, int target) {
		int len = static_cast<int>(nums.size());
		if (target <= nums[0]) return 0;
		if (target > nums[len - 1]) return len;
		int i = 0;
		while (i < len - 1) {
			if (target > nums[i] && target <= nums[i + 1]) return i + 1;
			else i = i + 1;
		}
        return 0;
	}

	int numTrees(int n) {
		vector<int> count = vector<int>(n + 1, 0);
		count[0] = 1;
		count[1] = 1;
		for (int i = 2; i < n + 1; i++) {
			for (int j = 0; j < i; j++) {
				count[i] = count[i] + count[j] * count[i - j - 1];
			}
		}
		return count[n];
	}

	string intToRoman(int num) {
		unordered_map<int, string> myMap = unordered_map<int, string>();
		myMap[1000] = "M";
		myMap[900] = "CM";
		myMap[500] = "D";
		myMap[400] = "CD";
		myMap[100] = "C";
		myMap[90] = "XC";
		myMap[50] = "L";
		myMap[40] = "XL";
		myMap[10] = "X";
		myMap[9] = "IX";
		myMap[5] = "V";
		myMap[4] = "IV";
		myMap[1] = "I";
		vector<int> myArray;
		myArray.push_back(1000);
		myArray.push_back(900);
		myArray.push_back(500);
		myArray.push_back(400);
		myArray.push_back(100);
		myArray.push_back(90);
		myArray.push_back(50);
		myArray.push_back(40);
		myArray.push_back(10);
		myArray.push_back(9);
		myArray.push_back(5);
		myArray.push_back(4);
		myArray.push_back(1);
		//myArray = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

		string romeNum;
		for (size_t i = 0; i < myArray.size(); i++) {
			int currLim = myArray[i];
			while (num >= currLim) {
				num = num - currLim;
				romeNum = romeNum + myMap[currLim];
			}
		}
		return romeNum;
	}

	int maxSubArray(vector<int>& nums) {
		int thissum = 0;
		int maxsum = INT_MIN;
		for (int num : nums) {
			if (thissum < 0) thissum = 0;
			thissum = thissum + num;
			maxsum = std::max(thissum, maxsum);
		}
		return maxsum;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() < 1) return NULL;
		return sortedArrayToBST(nums, 0, static_cast<int>(nums.size() - 1));
	}

	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (start > end) return NULL;
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);

		root->left = sortedArrayToBST(nums, start, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, end);
		return root;
	}

	int findMin(vector<int>& nums) {
		int left = 0;
		int right = static_cast<int>(nums.size()) - 1;
		int mid = 0;
		int min = nums[0];

		while (left < right - 1) {
			mid = (right + left) / 2;
			if (nums[mid] > nums[left]) {
				min = std::min(min, nums[left]);
				left = mid + 1;
			}
			else if (nums[mid] < nums[left]) {
				min = std::min(min, nums[mid]);
				right = mid - 1;
			}
		}

		min = std::min(min, nums[left]);
		min = std::min(min, nums[right]);

		return min;
	}

	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;

		int minPrice = prices[0];
		int profit = 0;
		for (int price : prices) {
			minPrice = std::min(minPrice, price);
			profit = std::max(profit, price - minPrice);
		}
		return profit;
	}

	int uniquePaths(int m, int n) {
		if (m == 0 || n == 0) return 0;
		if (m == 1 || n == 1) return 1;

		vector<vector<int>> dp(m, vector<int>(n));

		for (int i = 0; i < m; i++) {
			dp[i][0] = 1;
		}

		for (int j = 0; j < n; j++) {
			dp[0][j] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}

	vector<int> grayCode(int n) {
		vector<int> result = vector<int>();
		result.push_back(0);
		for (int i = 0; i < n; i++) {
			int highestBit = 1 << i;
			for (int j = static_cast<int>(result.size()) - 1; j >= 0; j--) {
				result.push_back(result[j] + highestBit);
			}
		}
		return result;
	}

	/*
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
	*/
	vector<string> generateParenthesis(int n) {
		vector<string> result = vector<string>();
		string s;
		generateParenthesis(result, s, n, n);
		return result;
	}

	void generateParenthesis(vector<string>& result, string s, int left, int right) {
		if (left > right) return;

		if (left == 0 && right == 0) {
			result.push_back(s);
			return;
		}

		if (left > 0) generateParenthesis(result, s + "(", left - 1, right);
		if (right > 0) generateParenthesis(result, s + ")", left, right - 1);

	}

	//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
	int kthSmallest(TreeNode* root, int k) {
		TreeNode* p = root;
		stack<TreeNode*> s = stack<TreeNode*>();
		int ks = 0;

		while (p || !s.empty()) {
			if (p) {
				s.push(p);
				p = p->left;
			}
			else {
				TreeNode* t = s.top();
				s.pop();
				k--;
				if (k == 0) return t->val;;
				p = t->right;
			}
		}
		return ks;
	}

	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* p = dummy;
		while (p->next && p->next->next) {
			ListNode* temp = p->next->next;
			p->next->next = temp->next;
			temp->next = p->next;
			p->next = temp;
			p = p->next->next;
		}
		return dummy->next;
	}


	void sortColors(vector<int>& nums) {
		int n = (int)nums.size();
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1 - i; j++) {
				if (nums[j] > nums[j + 1]) {
					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
		}
	}

	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		int m = (int)grid.size();
		int n = (int)grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
		for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (dp[i - 1][j] < dp[i][j - 1]) dp[i][j] = dp[i - 1][j] + grid[i][j];
				else dp[i][j] = dp[i][j - 1] + grid[i][j];
			}
		}
		return dp[m - 1][n - 1];
	}

	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> smatrix(n, vector<int>(n));
		int top = 0;
		int bottom = n - 1;
		int left = 0;
		int right = n - 1;

		int direction = 1;
		int elem = 0;
		while (elem < n*n) {
			if (direction == 1) {
				for (int i = left; i <= right; i++) {
					elem++;
					smatrix[top][i] = elem;
				}
				top++;
			}

			if (direction == 2) {
				for (int i = top; i <= bottom; i++) {
					elem++;
					smatrix[i][right] = elem;
				}
				right--;
			}

			if (direction == 3) {
				for (int i = right; i >= left; i--) {
					elem++;
					smatrix[bottom][i] = elem;
				}
				bottom--;
			}

			if (direction == 0) {
				for (int i = bottom; i >= top; i--) {
					elem++;
					smatrix[i][left] = elem;
				}
				left++;
			}

			direction = (direction + 1) % 4;
		}
		return smatrix;
	}

	int maxArea(vector<int>& height) {
		int left = 0;
		int right = (int)height.size() - 1;
		int curWater = 0;
		int maxWater = 0;
		while (left < right) {
			curWater = (right - left)*std::min(height[left], height[right]);
			maxWater = std::max(curWater, maxWater);
			if (height[left] < height[right]) left++;
			else right--;
		}
		return maxWater;
	}

	/*
	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
	Integers in each row are sorted in ascending from left to right.
	Integers in each column are sorted in ascending from top to bottom.
	*/
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int numRows = (int)matrix.size();
		int numCols = (int)matrix[0].size();
		int i = 0;
		int j = numCols - 1;
		while (i < numRows && j >= 0) {
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] > target) j--;
			else i++;
		}
		return false;
	}

	void setZeroes(vector<vector<int>>& matrix) {
		int numRows = (int)matrix.size();
		int numCols = (int)matrix[0].size();

		vector<bool> zeroRows = vector<bool>(numRows, false);
		vector<bool> zeroCols = vector<bool>(numCols, false);

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (matrix[i][j] == 0) {
					zeroRows[i] = true;
					zeroCols[j] = true;
				}
			}
		}

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (zeroRows[i] || zeroCols[j]) matrix[i][j] = 0;
			}
		}
	}

	int maxProfitCool(vector<int>& prices) {
		int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
		for (int price : prices) {
			pre_buy = buy;
			buy = max(pre_sell - price, pre_buy);
			pre_sell = sell;
			sell = max(pre_buy + price, pre_sell);
		}
		return sell;
	}

	bool isBadVersion(int version) {
		if (version > 100) return false;
		else return true;
	}

	int firstBadVersion(int n) {
		if (n == 1) return 1;

		int left = 1;
		int right = n;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid)) right = mid;
			else left = mid;
		}

		if (isBadVersion(left)) return left;

		return right;
	}

	int bulbSwitch(int n) {
		return static_cast<int>(std::sqrt(n));
	}

	int maxProduct(vector<string>& words) {
		int n = static_cast<int>(words.size());
		vector<vector<int>> elements(n, vector<int>(26, 0));
		for (int i = 0; i < n; i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				elements[i][words[i][j] - 'a']++;
			}
		}

		size_t ans = 0;
		bool noDuplicate;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				noDuplicate = true;
				for (int k = 0; k < 26; k++) {
					if (elements[i][k] != 0 && elements[j][k] != 0) {
						noDuplicate = false;
						break;
					}
				}
				if (noDuplicate && ans < words[i].length()*words[j].length()) {
					ans = static_cast<int>(words[i].length()*words[j].length());
				}
			}
		}
		return static_cast<int>(ans);
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> list;
		dfsCombinationSum3(result, 1, n, list, k);
		return result;
	}

	void dfsCombinationSum3(vector<vector<int>>& result, int start, int sum, vector<int>& list, int k) {
		if (sum == 0 && static_cast<int>(list.size()) == k) result.push_back(list);

		for (int i = start; i <= 9; i++) {
			if (sum - i < 0) break;
			if (static_cast<int>(list.size()) > k) break;

			list.push_back(i);
			dfsCombinationSum3(result, i + 1, sum - i, list, k);
			list.erase(list.end() - 1);
		}
	}

	/*
	Given an integer array with all positive numbers and no duplicates, 
	find the number of possible combinations that add up to a positive integer target.
	*/
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (int num : nums) {
				if (i >= num) dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> list;
		dfsCombine(result, list, n, k, 1);
		return result;
	}

	void dfsCombine(vector<vector<int>>& result, vector<int>& list, int n, int k, int level) {
		if (static_cast<int>(list.size()) == k) {
			result.push_back(list);
			return;
		}

		for (int i = level; i <= n; i++) {
			list.push_back(i);
			dfsCombine(result, list, n, k, i + 1);
			list.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> list;
		std::sort(candidates.begin(), candidates.end());
		dfsCombinationSum(result, list, candidates, target, 0);
		return result;
	}

	void dfsCombinationSum(vector<vector<int>>& result, vector<int>& list, vector<int> candidates, int target, int level) {
		if (target == 0 && list.size() > 0) {
			result.push_back(list);
			return;
		}

		for (int i = level; i < static_cast<int>(candidates.size()); i++) {
			if (target - candidates[i] < 0) break;
			list.push_back(candidates[i]);
			dfsCombinationSum(result, list, candidates, target - candidates[i], i);
			list.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> list;
		std::sort(candidates.begin(), candidates.end());
		dfsCombinationSum2(result, list, candidates, target, 0);
		return result;
	}

	void dfsCombinationSum2(vector<vector<int>>& result, vector<int>& list, vector<int> candidates, int target, int level) {
		if (target == 0) {
			result.push_back(list);
			return;
		}

		for (int i = level; i < static_cast<int>(candidates.size()); i++) {
			if (i > level && candidates[i] == candidates[i - 1]) continue;
			if (target - candidates[i] < 0) break;
			list.push_back(candidates[i]);
			dfsCombinationSum2(result, list, candidates, target - candidates[i], i + 1);
			list.pop_back();
		}
	}

	/*
	Given a sorted positive integer array nums and an integer n, 
	add/patch elements to the array such that any number in range [1, n] 
	inclusive can be formed by the sum of some elements in the array. 
	Return the minimum number of patches required.
	*/
	int minPatches(vector<int>& nums, int n) {
		int result = 0;
		long miss = 1;
		int i = 0;
		while (miss <= n) {
			if (i < static_cast<int>(nums.size()) && nums[i] <= miss) {
				miss += nums[i];
				i++;
			}
			else {
				miss += miss;
				result++;
			}
		}
		return result;
	}

	/*
	Given a digit string, return all possible letter combinations that the number could represent.
	A mapping of digit to letters (just like on the telephone buttons) is given below.
	*/
	vector<string> letterCombinations(string digits) {
		string trans[] = { "", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> result;
		string oneComb;
		if (digits.size() < 1) return result;
		dfsLetterCombinations(result, oneComb, trans, digits, 0);
		return result;
	}

	void dfsLetterCombinations(vector<string>& result, string& oneComb, string trans[], string digits, int dialed) {
		if (dialed == static_cast<int>(digits.size())) {
			result.push_back(oneComb);
			return;
		}

		int curDigit = static_cast<int>(digits[dialed] - 48);
		for (size_t i = 0; i < trans[curDigit].size(); i++) {
			oneComb.push_back(trans[curDigit][i]);
			dfsLetterCombinations(result, oneComb, trans, digits, dialed + 1);
			oneComb.pop_back();
		}
	}

	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int len = static_cast<int>(nums.size());
		vector<int> list(len, 1);

		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) list[i] = max(list[i], list[j] + 1);
			}
		}

		return *std::max_element(list.begin(), list.end());
	}

	vector<int> rightSideView(TreeNode* root) {
		vector<vector<int>> levelOrderTraversal = levelOrder(root);
		vector<int> result;
		int level = static_cast<int>(levelOrderTraversal.size());
		for (int i = 0; i < level; i++) {
			int rightView = levelOrderTraversal[i][levelOrderTraversal[i].size() - 1];
			result.push_back(rightView);
		}
		return result;
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> list;
		if (nums.empty()) return result;
		result.push_back(list);
		std::sort(nums.begin(), nums.end());
		dfsSubsets(result, list, nums, 0);
		return result;
	}

	void dfsSubsets(vector<vector<int>>& result, vector<int>& list, vector<int> nums, int level) {
		for (int i = level; i < static_cast<int>(nums.size()); i++) {
			list.push_back(nums[i]);
			result.push_back(list);
			dfsSubsets(result, list, nums, i + 1);
			list.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> list;
		if (nums.empty()) return result;
		result.push_back(list);
		std::sort(nums.begin(), nums.end());
		dfsSubsetsWithDup(result, list, nums, 0);
		return result;
	}

	void dfsSubsetsWithDup(vector<vector<int>>& result, vector<int>& list, vector<int> nums, int level) {
		for (int i = level; i < static_cast<int>(nums.size()); i++) {
			if (i > level && nums[i] == nums[i - 1]) continue;
			list.push_back(nums[i]);
			result.push_back(list);
			dfsSubsetsWithDup(result, list, nums, i + 1);
			list.pop_back();
		}
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		int m = static_cast<int>(obstacleGrid.size());
		int n = static_cast<int>(obstacleGrid[0].size());
		if (obstacleGrid[m - 1][n - 1] == 1) return 0;

		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = 1;
		for (int i = 1; i < m; i++) {
			if (obstacleGrid[i][0] == 1) {
				dp[i][0] = 0;
			}
			else {
				dp[i][0] = dp[i - 1][0];
			}
		}

		for (int j = 1; j < n; j++) {
			if (obstacleGrid[0][j] == 1) {
				dp[0][j] = 0;
			}
			else {
				dp[0][j] = dp[0][j - 1];
			}
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}

			}
		}
		return dp[m - 1][n - 1];
	}

	int maxProduct(vector<int>& nums) {
		if (nums.size() <= 0) return 0;
		int recordMax = nums[0];
		int currentMax = nums[0];
		int currentMin = nums[0];

		for (size_t i = 1; i < nums.size(); i++) {
			int temp = currentMax;
			currentMax = max(max(currentMax*nums[i], currentMin*nums[i]), nums[i]);
			currentMin = min(min(temp*nums[i], currentMin*nums[i]), nums[i]);
			recordMax = max(recordMax, currentMax);
		}
		return recordMax;
	}

	/*
	Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
	You may assume all four edges of the grid are all surrounded by water.
	*/
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid.size() == 0 || grid[0].size() == 0) return 0;
		int count = 0;
		for (int i = 0; i < static_cast<int>(grid.size()); i++) {
			for (int j = 0; j < static_cast<int>(grid[0].size()); j++) {
				if (grid[i][j] != '1') continue; // either water or visited
				else {
					count++;
					dfsIslands(grid, i, j);
				}
			}
		}
		return count;
	}

	void dfsIslands(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || i >= static_cast<int>(grid.size()) || j < 0 || j >= static_cast<int>(grid[0].size()))  return;
		if (grid[i][j] != '1') return;  //either water or visited
		grid[i][j] = '2';	// makr as visited
		dfsIslands(grid, i - 1, j);
		dfsIslands(grid, i + 1, j);
		dfsIslands(grid, i, j - 1);
		dfsIslands(grid, i, j + 1);
	}

	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<int> result;
		unordered_map<int, vector<int>> groupToIslands;
		unordered_map<int, int> islandToGroup;
		int groupNo = 1;
		for(auto pos : positions) {
			int row = pos.first;
			int col = pos.second;
			int p = row*n + col;	//Unique identifier for this island
			unordered_set<int> candidates;
			int top = row - 1 < 0 ? -1 : (row - 1)*n + col;
			int bot = row + 1 >= m ? -1 : (row + 1)*n + col;
			int left = col - 1 < 0 ? - 1 : row*n + col - 1;
			int right = col + 1 >= n ? - 1 : row*n + col + 1;
			if(islandToGroup.count(top)) candidates.insert(islandToGroup[top]);
			if(islandToGroup.count(bot)) candidates.insert(islandToGroup[bot]);
			if(islandToGroup.count(left)) candidates.insert(islandToGroup[left]);
			if(islandToGroup.count(right)) candidates.insert(islandToGroup[right]);

			if(candidates.empty()) { // This island does not belong to any existing group
				vector<int> islands;
				islands.push_back(p);
				groupToIslands.emplace(groupNo, islands);
				islandToGroup.emplace(p, groupNo);
				groupNo++;
			}
			else { // This island belongs to one or more existng group(s). Merge them.
				auto it = candidates.begin();
				int mergedGroup = *it;
				it++;
				while(it != candidates.end()) {
					for(int a : groupToIslands[*it]) {
						groupToIslands[mergedGroup].push_back(a);
						islandToGroup[a] = mergedGroup;
					}
					groupToIslands.erase(*it);
					it++;
				}
				groupToIslands[mergedGroup].push_back(p);
				islandToGroup.emplace(p, mergedGroup);
			}
			result.push_back(static_cast<int>(groupToIslands.size()));
		}
		return result;
	}

	/*
	Implement pow(x, n).
	*/
	double myPow(double x, int n) {
		if (n < 0) return 1.0 / helpPow(x, -n);
		else return helpPow(x, n);
	}

	double helpPow(double x, int n) {
		if (n == 0) return 1;
		double v = helpPow(x, n / 2);
		if (n % 2 == 0) {
			return v*v;
		}
		else {
			return v*v*x;
		}
	}

	/*
	Given an array of citations (each citation is a non-negative integer) of a researcher, 
	write a function to compute the researcher's h-index.
	*/
	int hIndex(vector<int>& citations) {
		std::sort(citations.begin(), citations.end(), std::greater<int>());
		for (int i = 0; i < static_cast<int>(citations.size()); i++) {
			if (i >= citations[i]) return i;
		}
		return static_cast<int>(citations.size());
	}

	string reverseString(string s) {
		string result = "";
		int i = static_cast<int>(s.length()) - 1;
		while (i >= 0) {
			result = result + s.at(i);
			i--;
		}
		return result;
	}

	int getSum(int a, int b) {
		if (b == 0) return a;
		int sum = a^b;
		int carry = (a&b) << 1;
		return getSum(sum, carry);
	}

	bool canConstruct(string ransomNote, string magazine) {
		int letter[26];
		for (int k = 0; k < 26; k++) letter[k] = 0;
		for (size_t i = 0; i < magazine.size(); i++) {
			letter[magazine.at(i) - 'a']++;
		}

		for (size_t j = 0; j < ransomNote.size(); j++) {
			if (--letter[ransomNote.at(j) - 'a'] < 0) return false;
		}
		return true;
	}

	string reverseVowels(string s) {
		set<char> vowels;
		vowels.insert('a');
		vowels.insert('e');
		vowels.insert('i');
		vowels.insert('o');
		vowels.insert('u');
		vowels.insert('A');
		vowels.insert('E');
		vowels.insert('I');
		vowels.insert('O');
		vowels.insert('U');

		int left = 0;
		int right = static_cast<int>(s.size()) - 1;
		while (left <= right) {
			if ((vowels.find(s[left]) == vowels.end())) {
				left++;
				continue;
			}

			if ((vowels.find(s[right]) == vowels.end())) {
				right--;
				continue;
			}

			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
		return s;
	}

	bool isPowerOfFour(int num) {
		if (num == 0) return false;
		int power = static_cast<int>(log(num) / log(4));
		if (pow(4, power) == num) return true;
		else return false;
	}

	bool isPowerOfThree(int n) {
		if (n == 0) return false;
		int power = static_cast<int>(floor(log(n) / log(3) + 0.5));
		if (pow(3, power) == n) return true;
		else return false;
	}

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1(nums1.begin(), nums1.end());
		set<int> s2;
		for (int element : nums2) {
			if (s1.count(element) > 0) s2.insert(element);
		}
		vector<int> result(s2.begin(), s2.end());
		return result;
	}

	vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());
		vector<int> result;
		vector<int>::iterator iter1 = nums1.begin();
		vector<int>::iterator iter2 = nums2.begin();
		while (iter1 != nums1.end() && iter2 != nums2.end()) {
			if (*iter1 > *iter2) iter2++;
			else if (*iter1 < *iter2) iter1++;
			else {
				result.push_back(*iter1);
				iter1++;
				iter2++;
			}
		}
		return result;
	}

	// This is a pre-defined API
	int guess(int num);

	int guessNumber(int n) {
		int L = 1;
		int R = n;
		while (L <= R) {
			int mid = L + ((R - L) >> 1);
			int res = guess(mid);
			if (res == 0) return mid;
			else if (res == 1)  L = mid + 1;
			else R = mid - 1;
		}
		return L;
	}

	vector<int> countBits(int num) {
		vector<int> result(num + 1, 0);
		for (int i = 0; i <= num; i++) {
			result[i] = result[i >> 1] + (i & 1);
		}
		return result;
	}

	//Count Numbers with Unique Digits
	int countNumbersWithUniqueDigits(int n) {
		n = min(n, 10);
		vector<int> dp(n + 1, 9);
		dp[0] = 1;
		for (int i = 2; i < n + 1; i++) {
			for (int k = 9; k >= 9 - i + 2; k--) {
				dp[i] = dp[i] * k;
			}
		}
		int ans = 0;
		for (int j = 0; j < n + 1; j++) ans = ans + dp[j];
		return ans;
	}

	bool increasingTriplet(vector<int>& nums) {
		int num1 = INT_MAX;
		int num2 = INT_MAX;
		for (int num : nums) {
			if (num <= num1) num1 = num;
			else if (num <= num2) num2 = num;
			else return true;
		}
		return false;
	}

	int integerBreak(int n) {
		if (n == 2 || n == 3) return n - 1;
		int result = 1;
		while (n > 4) {
			result = result * 3;
			n = n - 3;
		}
		return result*n;
	}

	bool isPerfectSquare(int num) {
		long long low = 1;
		long long high = num / 2 + 1;
		long long mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (num == mid*mid) return true;
			else if (num > mid*mid) low = mid + 1;
			else high = mid - 1;
		}
		return false;
	}

	vector<int> majorityElementII(vector<int>& nums) {
		vector<int> result;
		int m1 = NULL;
		int m2 = NULL;
		int c1 = 0;
		int c2 = 0;
		for (int i : nums) {
			if (i == m1) c1++;
			else if (i == m2) c2++;
			else if (c1 == 0) {
				m1 = i;
				c1 = 1;
			}
			else if (c2 == 0) {
				m2 = i;
				c2 = 1;
			}
			else {
				c1--;
				c2--;
			}
		}
		c1 = 0;
		c2 = 0;
		for (int i : nums) {
			if (i == m1) c1++;
			else if (i == m2) c2++;
		}
		if (c1 > static_cast<int>(nums.size()) / 3) result.push_back(m1);
		if (c2 > static_cast<int>(nums.size()) / 3) result.push_back(m2);
		return result;
	}

	vector<int> twoSum2(vector<int>& numbers, int target) {
		int left = 0;
		int right = static_cast<int>(numbers.size()) - 1;
		long long tempSum = 0;
		vector<int> result;
		while (left <= right) {
			tempSum = numbers[left] + numbers[right];
			if (tempSum == static_cast<long long>(target)) {
				result.push_back(left + 1);
				result.push_back(right + 1);
				return result;
			}
			else if (tempSum < static_cast<long long>(target)) {
				left++;
			}
			else right--;
		}
		return result;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> myMap;
		vector<int> result;
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			int diff = target - nums[i];
			if (myMap.find(diff) != myMap.end()) {
				result.push_back(myMap[diff]);
				result.push_back(i);
				return result;
			}
			myMap.emplace(nums[i], i);
		}
		return result;
	}

	int rangeBitwiseAnd(int m, int n) {
		int d = INT_MAX;
		while ((m&d) != (n&d)) {
			d = d << 1;
		}
		return m&d;
	}

	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) return 0;
		int ans = 1;
		int n = static_cast<int>(nums.size());
		for (int cur = 1, prev = 0; cur < n; prev = cur, cur++) {
			if (nums[cur] > nums[prev]) {
				ans++;
				while ((cur + 1 < n) && (nums[cur + 1] >= nums[cur])) cur++;
			}
			else if (nums[cur] < nums[prev]) {
				ans++;
				while ((cur + 1 < n) && (nums[cur + 1] <= nums[cur])) cur++;
			}
		}
		return ans;
	}

	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* fakeHead = new ListNode(0);
		ListNode* cur = head;
		while (cur != NULL) {
			ListNode* next = cur->next;
			ListNode* pre = fakeHead;
			while (pre->next != NULL && pre->next->val < cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			cur = next;
		}
		return fakeHead->next;
	}

	int findDuplicate(vector<int>& nums) {
		int low = 1;
		int high = static_cast<int>(nums.size()) - 1;
		while (low < high) {
			int mid = (low + high) / 2;
			int c = 0;

			for (int i : nums) {
				if (i <= mid) c++;
			}

			if (c > mid) high = mid;
			else low = mid + 1;
		}
		return low;
	}

	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX - 1);
		dp[0] = 0;
		for (int i = 1; i < amount + 1; i++) {
			for (size_t j = 0; j < coins.size(); j++) {
				if (coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}

	bool canJump(vector<int>& nums) {
		int maxDist = 0;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i <= maxDist && maxDist < n - 1; i++) {
			if (maxDist < i + nums[i]) maxDist = i + nums[i];
		}
		return maxDist >= n - 1;
	}

	int lengthOfLongestSubstring(string s) {
		int maxLen = 0;
		unordered_set<char> myMap;
		int start = 0;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			if (myMap.find(s[i]) == myMap.end()) myMap.insert(s[i]);
			else {
				maxLen = max(maxLen, static_cast<int>(myMap.size()));
				while (start < i && s[start] != s[i]) {
					myMap.erase(s[start]);
					start++;
				}
				start++;
			}
		}
		return max(maxLen, static_cast<int>(myMap.size()));
	}

	
	vector<string> generatePossibleNextMoves(string s) {
		vector<string> result;
		for (int i = 0; i + 1 < static_cast<int>(s.size()); i++) {
			if (s[i] == '+' && s[i + 1] == '+') {
				s[i] = '-';
				s[i + 1] = '-';
				result.push_back(s);
				s[i] = '+';
				s[i + 1] = '+';
			}
		}
		return result;
	}

	int shortestDistance(vector<string>& words, string word1, string word2) {
		int dist = INT_MAX;
		int pos1 = -1;
		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			if (words[i].compare(word1) == 0 || words[i].compare(word2) == 0) {
				if (pos1 == -1) {
					pos1 = i;
				}
				else {
					if (words[i].compare(words[pos1]) != 0) {
						dist = min(abs(i - pos1), dist);
						pos1 = i;
					}
					else pos1 = i;
				}
			}
		}
		return dist;
	}

	/*
	Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
	determine if a person could attend all meetings.
	*/
	bool canAttendMeetings(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), compareInterval);
		for (int i = 0; i < static_cast<int>(intervals.size()) - 1; i++) {
			if (intervals[i].end > intervals[i + 1].start) return false;
		}
		return true;
	}

	static bool compareInterval(Interval& interval1, Interval& interval2) {
		if (interval1.start == interval2.start) {
			return interval1.end < interval2.end;
		}
		else {
			return interval1.start < interval2.start;
		}

	}

	/*
	Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
	find the minimum number of conference rooms required.
	*/
	int minMeetingRooms(vector<Interval>& intervals) {
		int n = static_cast<int>(intervals.size());
		if (n < 1) return 0;
		int count = 0;
		sort(intervals.begin(), intervals.end(), compareInterval);
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(intervals[0].end);

		for (int i = 1; i < n; i++) {
			if (intervals[i].start < pq.top()) {
				count++;
			}
			else {
				pq.pop();
			}
			pq.push(intervals[i].end);
		}
		return count;
	}

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), compareInterval);
		int i = 0;
		while (i < static_cast<int>(intervals.size())) {
			Interval currItv = intervals[i];
			int j = i + 1;
			while (j < static_cast<int>(intervals.size())) {
				Interval nextItv = intervals[j];
				if (nextItv.start <= currItv.end) {
					currItv.end = max(currItv.end, nextItv.end);
					j++;
				}
				else {
					i = j;
					if (j == static_cast<int>(intervals.size()) - 1) {
						result.push_back(currItv);
						result.push_back(nextItv);
						return result;
					}
					break;
				}
			}
			result.push_back(currItv);
			i = j;
		}
		return result;
	}

	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), compareInterval);
		return merge(intervals);
	}

	/*
	Given a collection of intervals, find the minimum number of intervals 
	you need to remove to make the rest of the intervals non-overlapping.
	*/
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		int len = static_cast<int>(intervals.size());
		if (len <= 1) return 0;
		int result = 0;
		int last = 0;
		sort(intervals.begin(), intervals.end(), compareInterval);
		for (int i = 1; i < len; i++) {
			if (intervals[i].start < intervals[last].end) {
				result++;
				if (intervals[i].end < intervals[last].end) last = i;
			}
			else {
				last = i;
			}
		}
		return result;
	}

	/*
	Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
	Given target value is a floating point.
	You are guaranteed to have only one unique value in the BST that is closest to the target.
	*/
	int closestValue(TreeNode* root, double target) {
		int result = root->val;
		TreeNode* p = root;
		while (p) {
			if (abs(result - target) >= (p->val - target)) result = p->val;
			p = target < p->val ? p->left : p->right;
		}
		return result;
	}


	/*
	A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
	Write a function to determine if a number is strobogrammatic. The number is represented as a string.
	For example, the numbers "69", "88", and "818" are all strobogrammatic.
	*/
	bool isStrobogrammatic(string num) {
		map<char, char> myRule;
		myRule.emplace('0', '0');
		myRule.emplace('1', '1');
		myRule.emplace('6', '9');
		myRule.emplace('8', '8');
		myRule.emplace('9', '6');
		int n = static_cast<int>(num.size());
		if ((n / 2 * 2 == n) || (n / 2 * 2 != n && (num[n / 2] == '0' || num[n / 2] == '1' || num[n / 2] == '8')))
		{
			for (int i = n / 2 - 1; i >= 0; i--) {
				if (myRule.find(num[i]) != myRule.end()) {
					if (myRule[num[i]] == num[n - 1 - i]) continue;
					else return false;
				}
				else return false;
			}
		}
		else return false;
		return true;
	}

	/*
	A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
	Find all strobogrammatic numbers that are of length = n.
	*/
	vector<string> findStrobogrammatic(int n) {
		vector<string> result;
		unordered_map<char, char> myRule;
		myRule.emplace('0', '0');
		myRule.emplace('1', '1');
		myRule.emplace('6', '9');
		myRule.emplace('8', '8');
		myRule.emplace('9', '6');
		constructStrobogram(result, "", myRule, n);
		return result;
	}

	void constructStrobogram(vector<string>& result, string strobogram, unordered_map<char, char>& myRule, int n) {
		if(n == 0) {
			if(strobogram.size() > 1 && strobogram[0] == '0') return;
			result.push_back(strobogram);
		}
		else if(n == 1) {
			constructStrobogram(result, strobogram.substr(0, strobogram.size()/2) + '0' + strobogram.substr(strobogram.size()/2), myRule, 0);
			constructStrobogram(result, strobogram.substr(0, strobogram.size()/2) + '1' + strobogram.substr(strobogram.size()/2), myRule, 0);
			constructStrobogram(result, strobogram.substr(0, strobogram.size()/2) + '8' + strobogram.substr(strobogram.size()/2), myRule, 0);
		}
		else {
			for(auto p : myRule) {
				constructStrobogram(result, p.first + strobogram + p.second, myRule, n - 2);
			}
		}
	}

	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> result;
		vector<int> leaves;
		while (root) {
			root = removeLeaves(root, leaves);
			result.push_back(leaves);
		}
		return result;
	}

	TreeNode* removeLeaves(TreeNode* root, vector<int>& leaves) {
		if (!root) return NULL;
		if (!root->left && !root->right) {
			leaves.push_back(root->val);
			root = NULL;
			return root;
		}
		root->left = removeLeaves(root->left, leaves);
		root->right = removeLeaves(root->right, leaves);
		return root;
	}

	/*
	Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
	For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
	*/
	void wiggleSort(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		for (int i = 1; i < n; i++) {
			if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
		}
	}

	/*
	Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
	*/
	void wiggleSortII(vector<int>& nums) {
		vector<int> temp = nums;
		int n = static_cast<int>(nums.size());
		int k = (n-1)/2;
		int j = n - 1;
		sort(temp.begin(), temp.end());
		for(int i = 0; i < n; i++) {
			if(i%2 == 0) {
				nums[i] = temp[k];
				k--;
			}
			else {
				nums[i] = temp[j];
				j--;
			}
		}
	}

	ListNode* plusOne(ListNode* head) {
		stack<ListNode*> myStack;
		ListNode* cur = head;
		while (cur) {
			myStack.push(cur);
			cur = cur->next;
		}
		int carry = 1;
		while (!myStack.empty() && carry > 0) {
			ListNode* t = myStack.top();
			myStack.pop();
			int sum = t->val + carry;
			t->val = sum % 10;
			carry = sum / 10;
		}

		if (carry) {
			ListNode* fakeHead = new ListNode(1);
			fakeHead->next = head;
			head = fakeHead;
		}
		return head;
	}

	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		int l = static_cast<int>(A.size());
		int m = static_cast<int>(B.size());
		int n = static_cast<int>(B[0].size());
		vector<vector<int>> C(l, vector<int>(n, 0));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j]) {
					for (int k = 0; k < n; k++) C[i][k] += A[i][j] * B[j][k];
				}
			}
		}
		return C;
	}

	int shortestDistance3(vector<string>& words, string word1, string word2) {
		int dist = INT_MAX;
		int pos1 = -1;
		for (int i = 0; i < static_cast<int>(words.size()); i++) {
			if (words[i].compare(word1) == 0 || words[i].compare(word2) == 0) {
				if (pos1 == -1) {
					pos1 = i;
				}
				else {
					if (words[i].compare(words[pos1]) != 0 && word1.compare(word2) != 0) {
						dist = min(abs(i - pos1), dist);
						pos1 = i;
					}
					else if (words[i].compare(words[pos1]) == 0 && word1.compare(word2) == 0) {
						dist = min(abs(i - pos1), dist);
						pos1 = i;
					}
					pos1 = i;
				}
			}
		}
		return dist;
	}

	int countComponents(int n, vector<pair<int, int>>& edges) {
		int result = 0;
		vector<bool> visited(n, false);
		vector <vector<int>> adjacent(n);
		for (auto edge : edges) {
			adjacent[edge.first].push_back(edge.second);
			adjacent[edge.second].push_back(edge.first);
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				result++;
				dfsCountComponents(adjacent, visited, i);
			}
		}
		return result;
	}

	void dfsCountComponents(vector<vector<int>>& adjacent, vector<bool>& visited, int i) {
		if (visited[i]) return;
		visited[i] = true;
		for (int j = 0; j < static_cast<int>(adjacent[i].size()); j++) {
			dfsCountComponents(adjacent, visited, adjacent[i][j]);
		}
	}

	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		sort(nums.begin(), nums.end());
		int minDiff = INT_MAX;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 2; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				int diff = abs(target - sum);
				if (sum == target) {
					return sum;
				}
				else if (sum > target) {
					k--;
				}
				else {
					j++;
				}
				if (diff < minDiff) {
					minDiff = diff;
					result = sum;
				}
			}
		}
		return result;
	}

	vector<vector<int>> threeSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		vector<int> oneSolution;
		sort(nums.begin(), nums.end());
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == target) {
					oneSolution.push_back(nums[i]);
					oneSolution.push_back(nums[j]);
					oneSolution.push_back(nums[k]);
					result.push_back(oneSolution);
					oneSolution.clear();
					while (j < k && nums[j] == nums[j + 1]) j++;
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
					j++;
				}
				else if (nums[i] + nums[j] + nums[k] > target) {
					k--;
				}
				else {
					j++;
				}
			}
		}
		return result;
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		vector<int> comb;
		sort(nums.begin(), nums.end());
		nSum(nums, target, 4, comb, result);
		return result;
	}

	void nSum(vector<int>& nums, int target, int N, vector<int>& comb, vector<vector<int>>& result) {
		if (static_cast<int>(nums.size()) < N || target < nums[0] * N || target > nums.back()*N) {
			return;		// early termination
		}
		if (N == 2) {
			int left = 0;
			int right = static_cast<int>(nums.size());
			while (left < right) {
				int s = nums[left] + nums[right];
				if (s == target) {
					comb.push_back(nums[left]);
					comb.push_back(nums[right]);
					result.push_back(comb);
					comb.pop_back();
					comb.pop_back();
					while (left < right && nums[left + 1] == nums[left]) {
						left++;
					}
					left++;
					right--;
				}
				else if (s < target) {
					left++;
				}
				else {
					right--;
				}
			}
		}
		else {
			for (int i = 0; i < static_cast<int>(nums.size()) - N + 1; i++) {
				if (i != 0 && nums[i] == nums[i - 1]) continue;
				vector<int> nums_new;
				nums_new.assign(nums.begin() + i + 1, nums.end());
				comb.push_back(nums[i]);
				nSum(nums_new, target - nums[i], N - 1, comb, result);
				comb.pop_back();
			}
		}
	}

	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int cnt = 0;
		int n = static_cast<int>(nums.size());
		for (int i = 0; i < n - 2; i++) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] >= target) k--;
				else {
					cnt = cnt + (k - j);
					j++;
				}
			}
		}
		return cnt;
	}

	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		int n = static_cast<int>(nums.size());
		vector<int> result(n, 0);
		int i = 0;
		int j = n - 1;
		int idx = a >= 0 ? n - 1 : 0;
		while (i <= j) {
			if (a >= 0) {
				result[idx--] = helpTransformedArray(nums[i], a, b, c) >= helpTransformedArray(nums[j], a, b, c) ? helpTransformedArray(nums[i++], a, b, c) : helpTransformedArray(nums[j--], a, b, c);
			}
			else {
				result[idx++] = helpTransformedArray(nums[i], a, b, c) <= helpTransformedArray(nums[j], a, b, c) ? helpTransformedArray(nums[i++], a, b, c) : helpTransformedArray(nums[j--], a, b, c);
			}
		}
		return result;
	}

	int helpTransformedArray(int x, int a, int b, int c) {
		return a*x*x + b*x + c;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		int len1 = 0;
		int len2 = 0;
		while (p1) {
			len1++;
			p1 = p1->next;
		}
		while (p2) {
			len2++;
			p2 = p2->next;
		}
		if (len1 < len2) {
			p1 = l2;
			p2 = l1;
		}
		else {
			p1 = l1;
			p2 = l2;
		}
		int a;
		int b;
		while (p1 || p2) {
			if (p2) {
				a = p1->val;
				b = p2->val;
				p1->val = (a + b + carry) % 10;
				carry = (a + b + carry) / 10;
				p1 = p1->next;
				p2 = p2->next;
			}
			else {
				a = p1->val;
				p1->val = (a + carry) % 10;
				carry = (a + carry) / 10;
				p1 = p1->next;
			}
		}
		if (carry == 1) {
			if (len1 < len2) p1 = l2;
			else p1 = l1;
			while (p1->next) {
				p1 = p1->next;
			}
			p1->next = new ListNode(1);
		}
		if (len1 < len2) return l2;
		else return l1;
	}

	bool knows(int a, int b);

	int findCelebrity(int n) {
		int celebrity = 0;
		for (int i = 1; i < n; i++) {
			if (knows(celebrity, i)) celebrity = i;
		}

		for (int i = 0; i < n; i++) {
			if (i != celebrity && (knows(celebrity, i) || !knows(i, celebrity))) return -1;
		}
		return celebrity;
	}

	void reverseWords(string &s) {
		int i = 0;
		int j = 0;
		int l = 0;
		int len = static_cast<int>(s.length());
		int wordCount = 0;
		while (true) {
			while (i < len && s[i] == ' ') {
				i++;
			}
			if (i == len) break;
			if (wordCount > 0) {
				s[j] = ' ';
				j++;
			}
			l = j;
			while (i < len && s[i] != ' ') {
				s[j] = s[i];
				i++;
				j++;
			}
			reverseWord(s, l, j - 1);
			wordCount++;
		}
		s.resize(j);
		reverseWord(s, 0, j - 1);
	}

	void reverseWord(string &s, int i, int j) {
		while (i < j) {
			char t = s[i];
			s[i++] = s[j];
			s[j--] = t;
		}
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* cur = head;
		stack<ListNode*> myStack;
		int a = 1;
		while (a < m)
		{
			cur = cur->next;
			a++;
		}
		while (a <= n) {
			myStack.push(cur);
			cur = cur->next;
			a++;
		}
		ListNode* rest = cur;
		a = 1;
		ListNode* fakeHead = new ListNode(0);
		fakeHead->next = head;
		cur = fakeHead;
		while (a < m) {
			cur = cur->next;
			a++;
		}
		while (!myStack.empty()) {
			ListNode* t = myStack.top();
			myStack.pop();
			cur->next = t;
			cur = cur->next;
		}
		cur->next = rest;
		return fakeHead->next;
	}

	/*
	Given two strings s and t which consist of only lowercase letters.
	String t is generated by random shuffling string s and then add one more letter at a random position.
	Find the letter that was added in t.
	*/
	char findTheDifference(string s, string t) {
		unordered_map<char, int> dic;
		for (int i = 0; i < static_cast<int>(s.length()); i++) {
			if (dic.find(s[i]) == dic.end()) {
				dic.emplace(s[i], 1);
			}
			else dic[s[i]]++;
		}
		int j;
		for (j = 0; j < static_cast<int>(t.length()); j++) {
			if (dic.find(t[j]) == dic.end()) {
				return t[j];
			}
			else if (--dic[t[j]] < 0) {
				return t[j];
			}
		}
		return t[j];
	}

	int integerReplacement(int n) {
		if (n == 1) return 0;
		if (n % 2 == 0) return integerReplacement(n / 2) + 1;
		else return min(integerReplacement(n + 1) + 1, integerReplacement(n - 1) + 1);
	}

	int maxRotateFunction(vector<int>& A) {
		int len = static_cast<int>(A.size());
		int sum = 0;
		int temp = 0;
		for (int i = 0; i < len; i++) {
			sum = sum + A[i];
			temp = temp + i*A[i];
		}
		int result = temp;
		for (int i = 1; i < len; i++) {
			temp = temp + sum - len*A[len - i];
			result = max(temp, result);
		}
		return result;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> myMap;
		for (int elem : nums) {
			if (myMap.find(elem) != myMap.end()) {
				myMap[elem]++;
			}
			else {
				myMap.emplace(elem, 1);
			}
		}
		int maxCount = 0;
		for (auto onePair : myMap) {
			int count = onePair.second;
			maxCount = max(maxCount, count);
		}
		vector<vector<int>> myArray(maxCount + 1, vector<int>());
		for (auto onePair : myMap) {
			myArray[onePair.second].push_back(onePair.first);
		}

		vector<int> result;
		for (int i = maxCount; i >= 0; i--) {
			if (!myArray[i].empty()) {
				for (int elem : myArray[i]) {
					result.push_back(elem);
				}
			}
		}
		result.resize(k);
		return result;
	}

	bool isSubsequence(string s, string t) {
		int len = static_cast<int>(s.length());
		size_t pFound = 0;
		size_t cFound;
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				cFound = t.find(s[i]);
			}
			else {
				cFound = t.find(s[i], pFound + 1);
			}
			if (cFound == string::npos) {
				return false;
			}
			else {
				pFound = cFound;
			}
		}
		return true;
	}

	int maxPoints(vector<Point>& points) {
		int result = 0;
		int num = static_cast<int>(points.size());
		for (int i = 0; i < num; i++) {
			int samePoint = 1;
			unordered_map<double, int> map;
			for (int j = i + 1; j < num; j++) {
				if (points[i].x == points[j].x && points[i].y == points[j].y) {
					samePoint++;
				}
				else if (points[i].x == points[j].x) {
					map[INT_MAX]++;
				}
				else {
					double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
					map[slope]++;
				}
			}
			int localMax = 0;
			for (auto it = map.begin(); it != map.end(); it++) {
				localMax = max(localMax, it->second);
			}
			localMax += samePoint;
			result = max(result, localMax);
		}
		return result;
	}

	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		unordered_map<RandomListNode*, RandomListNode*> myMap;
		RandomListNode* p = head;
		RandomListNode* newHead = new RandomListNode(head->label);
		RandomListNode* q = newHead;
		myMap.emplace(p, q);
		p = p->next;
		while (p) {
			RandomListNode* temp = new RandomListNode(p->label);
			q->next = temp;
			q = q->next;
			myMap.emplace(p, q);
			p = p->next;
		}

		p = head;
		q = newHead;
		while (p) {
			if (p->random) {
				q->random = myMap[p->random];
			}
			else {
				q->random = NULL;
			}
			q = q->next;
			p = p->next;
		}
		return newHead;
	}

	string largestNumber(vector<int>& nums) {
		string result = "";
		sort(nums.begin(), nums.end(), compare);
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			result = result + to_string(nums[i]);
		}
		if (result[0] == '0') {
			return "0";
		}
		return result;
	}

	static bool compare(int a, int b) {
		string x = to_string(a);
		string y = to_string(b);
		return x + y > y + x;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = static_cast<int>(nums1.size());
		int n = static_cast<int>(nums2.size());
		int total = m + n;
		if (total % 2 == 0) {
			return (findKth(total / 2, nums1, nums2, 0, 0) + findKth(total / 2 + 1, nums1, nums2, 0, 0)) / 2;
		}
		else {
			return findKth(total / 2 + 1, nums1, nums2, 0, 0);
		}
	}

	double findKth(int k, vector<int> nums1, vector<int> nums2, int start1, int start2) {
		if (start1 >= static_cast<int>(nums1.size())) {
			return nums2[start2 + k - 1];
		}
		if (start2 >= static_cast<int>(nums2.size())) {
			return nums1[start1 + k - 1];
		}
		if (k == 1) {
			return min(nums1[start1], nums2[start2]);
		}
		int m1 = start1 + k / 2 - 1;
		int m2 = start2 + k / 2 - 1;
        int mid1 = 0;
		int mid2 = 0;
		if (m1 < static_cast<int>(nums1.size())) {
			mid1 = nums1[m1];
		}
		else {
			mid2 = INT_MAX;
		}
		if (m2 < static_cast<int>(nums2.size())) {
			mid2 = nums2[m2];
		}
		else {
			mid2 = INT_MAX;
		}
		if (mid1 < mid2) {
			return findKth(k - k / 2, nums1, nums2, m1 + 1, start2);
		}
		else {
			return findKth(k - k / 2, nums1, nums2, start1, m2 + 1);
		}
	}
	/*
	Implement wildcard pattern matching with support for '?' and '*'.
	'?' Matches any single character.
	'*' Matches any sequence of characters (including the empty sequence).
	*/
	bool isMatchWildcard(string s, string p) {
		int lenS = static_cast<int>(s.length());
		int lenP = static_cast<int>(p.length());
		int sid = 0;
		int pid = 0;
		int starIdx = -1;
		int savedSid = -1;
		while (sid < lenS) {
			if (s[sid] == p[pid] || p[pid] == '?') {
				sid++;
				pid++;
			}
			else if (p[pid] == '*') {
				starIdx = pid;
				pid++;
				savedSid = sid;
			}
			else {
				if (starIdx > -1) {
					pid = starIdx + 1;
					savedSid++;
					sid = savedSid;
				}
				else {
					return false;
				}
			}
		}
		while (p[pid] == '*') pid++;
		return pid == lenP;
	}

	/*
	Implement regular expression matching with support for '.' and '*'.
	'.' Matches any single character.
	'*' Matches zero or more of the preceding element.
	*/
	bool isMatchReg(string s, string p) {
		return isMatchReg(s, 0, p, 0);
	}

	bool isMatchReg(string s, size_t i, string p, size_t j) {
		if (j == p.size()) return i == s.size();

		//next char is not '*', must match current char
		if (j + 1 == p.size() || p[j + 1] != '*') {
			if (i == s.size() || (p[j] != s[i] && p[j] != '.')) {
				return false;
			}
			else return isMatchReg(s, i + 1, p, j + 1);
		}

		//next char is '*'
		while (i != s.size() && (s[i] == p[j] || p[j] == '.')) {
			if (isMatchReg(s, i, p, j + 2)) return true;
			i++;
		}
		return isMatchReg(s, i, p, j + 2);
	}

	/*
	Given a string s and a dictionary of words dict, 
	determine if s can be segmented into a space-separated sequence of one or more dictionary words.
	*/
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = static_cast<int>(s.length());
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[len];
	}

	vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
		int len = static_cast<int>(s.length());
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		vector<string> path;
		vector<string> result;
		for (int i = 1; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		dfsWordBreak(s, wordDict, path, result, 0, dp);

		return result;
	}

	void dfsWordBreak(string s, unordered_set<string> wordDict, vector<string>& path, vector<string>& result, int index, vector<bool>& canBreak) {
		int len = static_cast<int>(s.length());
		if (len == index) {
			string oneSentence = "";
			for (string w : path) {
				oneSentence = oneSentence + w;
				oneSentence = oneSentence + " ";
			}
			oneSentence.erase(oneSentence.length() - 1);
			result.push_back(oneSentence);
			return;
		}

		if (!canBreak[index]) {
			return;
		}

		for (int i = index; i < len; i++) {
			string remain = s.substr(index, i + 1 - index);
			if (wordDict.find(remain) != wordDict.end()) {
				path.push_back(remain);
				dfsWordBreak(s, wordDict, path, result, i + 1, canBreak);
				path.pop_back();
			}
		}
	}

	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		if (root) {
			TreeNode* left = root->left;
			TreeNode* right = root->right;
			if (left && (left->left == NULL) && (left->right == NULL)) {
				sum = sum + left->val + sumOfLeftLeaves(right);
			}
			else {
				sum = sum + sumOfLeftLeaves(left) + sumOfLeftLeaves(right);
			}
		}
		return sum;
	}

	//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	int findNthDigit(int n) {
		long long len = 1, cnt = 9, start = 1;
		while (static_cast<long long>(n) > len * cnt) {
			n = static_cast<int>(n -len * cnt);
			++len;
			cnt *= 10;
			start *= 10;
		}
		start += (n - 1) / len;
		string t = to_string(start);
		return t[(n - 1) % len] - '0';
	}

	/*
	Equations are given in the format A / B = k, where A and B are variables represented as strings, 
	and k is a real number (floating point number). 
	Given some queries, return the answers. If the answer does not exist, return -1.0.
	*/
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, int> sampleMap;
		int index = 0;
		for (auto equation : equations) {
			if (sampleMap.find(equation.first) == sampleMap.end()) {
				sampleMap.emplace(equation.first, index++);
			}
			if (sampleMap.find(equation.second) == sampleMap.end()) {
				sampleMap.emplace(equation.second, index++);
			}
		}
		vector<vector<double>> graph(sampleMap.size(), vector<double>(sampleMap.size(), INT_MAX));
		for (size_t i = 0; i < values.size(); i++) {
			int idx1 = sampleMap[equations[i].first];
			int idx2 = sampleMap[equations[i].second];
			graph[idx1][idx2] = values[i];
			graph[idx2][idx1] = 1.0 / values[i];
		}

		for (size_t k = 0; k < sampleMap.size(); k++) {
			for (size_t i = 0; i < sampleMap.size(); i++) {
				for (size_t j = 0; j < sampleMap.size(); j++) {
					if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
						graph[i][j] = min(graph[i][k] * graph[k][j], graph[i][j]);
					}
				}
			}
		}

		vector<double> result;
		for (auto query : queries) {
			if (sampleMap.find(query.first) == sampleMap.end() || sampleMap.find(query.second) == sampleMap.end()) {
				result.push_back(-1.0);
			}
			else {
				int idx1 = sampleMap[query.first];
				int idx2 = sampleMap[query.second];
				double calc = graph[idx1][idx2] == INT_MAX ? -1 : graph[idx1][idx2];
				result.push_back(calc);
			}
		}
		return result;
	}

	vector<int> lexicalOrder(int n) {
		vector<int> result;
		for (int i = 1; i <= 9; i++) {
			lexicalOrderDfs(i, n, result);
		}
		return result;
	}

	void lexicalOrderDfs(int cur, int n, vector<int>& result) {
		if (cur > n) return;
		result.push_back(cur);
		for (int i = 0; i < 10; i++) {
			if (cur * 10 + i > n) {
				return;
			}
			else {
				lexicalOrderDfs(cur * 10 + i, n, result);
			}
		}
	}


	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;
		pathSum(root, sum, path, result);
		return result;
	}

	void pathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result) {
		if (!root) return;
		if (sum - root->val == 0 && root->left == NULL && root->right == NULL) {
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root->val);
		sum = sum - root->val;
		pathSum(root->left, sum, path, result);
		pathSum(root->right, sum, path, result);
		path.pop_back();
	}

	/*
	You are given a binary tree in which each node contains an integer value.
	Find the number of paths that sum to a given value.
	The path does not need to start or end at the root or a leaf,
	but it must go downwards (traveling only from parent nodes to child nodes).
	*/
	int pathSumIII(TreeNode* root, int sum) {
		if (!root) return 0;
		vector<int> path;
		vector<int> numPath;
		numPath.push_back(0);
		dfsPathSum(root, sum, path, numPath);
		return numPath[0];
	}

	void dfsPathSum(TreeNode* root, int sum, vector<int>& path, vector<int>& numPath) {
		if (!root) return;
		if (root->val == sum) {
			path.push_back(root->val);
			numPath[0] = numPath[0] + 1;
			path.pop_back();
		}

		if (path.empty()) {
			dfsPathSum(root->left, sum, path, numPath);
			dfsPathSum(root->right, sum, path, numPath);
		}

		path.push_back(root->val);
		sum = sum -  root->val;
		dfsPathSum(root->left, sum, path, numPath);
		dfsPathSum(root->right, sum, path, numPath);
		path.pop_back();
		return;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto prereq : prerequisites) {
			graph[prereq.first].insert(prereq.second);
		}
		vector<bool> visitedGlobal(numCourses, false);
		vector<bool> visitedCurrent(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			if (!visitedGlobal[i] && graphCycleDfs(graph, i, visitedGlobal, visitedCurrent)) return false;
		}
		return true;
	}

	bool graphCycleDfs(vector<unordered_set<int>> graph, int curNode, vector<bool>& visitedGlobal, vector<bool>& visitedCurrent) {
		if (visitedCurrent[curNode]) return false;
		visitedGlobal[curNode] = true;
		visitedCurrent[curNode] = true;
		for (int neighbor : graph[curNode]) {
			if (visitedCurrent[neighbor] || graphCycleDfs(graph, neighbor, visitedGlobal, visitedCurrent)) {
				return true;
			}
		}
		visitedCurrent[curNode] = false;
		return false;
	}

	/*
	A binary watch has 4 LEDs on the top which represent the hours (0-11), 
	and the 6 LEDs on the bottom represent the minutes (0-59).
	Each LED represents a zero or one, with the least significant bit on the right.
	*/
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (int hour = 0; hour < 12; hour++) {
			for (int minute = 0; minute < 60; minute++) {
				if (static_cast<int>(bitset<10>(hour).count() + bitset<10>(minute).count()) == num) {
					string time = to_string(hour) + ":";
					if (minute < 10) {
						time = time + "0" + to_string(minute);
					}
					else {
						time = time + to_string(minute);
					}
					result.push_back(time);
				}
			}
		}
		return result;
	}

	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		string curSeq = "";
		unordered_map<string, int> dnaMap;
		for (size_t i = 0; i < s.length(); i++) {
			if (curSeq.length() == 10) {
				curSeq.erase(0, 1);
				curSeq = curSeq + s[i];
			}
			else {
				curSeq = curSeq + s[i];
			}

			if (curSeq.length() == 10) {
				if (dnaMap.find(curSeq) == dnaMap.end()) {
					dnaMap[curSeq] = 1;
				}
				else {
					dnaMap[curSeq]++;
				}
			}
		}

		for (auto seq : dnaMap) {
			if (seq.second > 1) {
				result.push_back(seq.first);
			}
		}

		return result;
	}

	int lastRemaining(int n) {
		int start = 1;
		int gap = 1;
		int cnt = 0;
		while (n > 1) {
			n = n / 2;
			gap = gap * 2;
			cnt++;
			if (cnt % 2) {
				start = start + gap / 2 + (n - 1)*gap;
			}
			else {
				start = start - gap / 2 - (n - 1)*gap;
			}
		}
		return start;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int start = 0;
		int end = static_cast<int>(nums.size()) - 1;
		bool isFind = false;
		int findIdx = 0;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (nums[mid] > target) {
				end = mid - 1;
			}
			else if (nums[mid] < target) {
				start = mid + 1;
			}
			else {
				isFind = true;
				findIdx = mid;
				break;
			}
		}
		int rangeStart = -1;
		int rangeEnd = -1;
		vector<int> result;
		if (isFind) {
			rangeStart = findIdx;
			rangeEnd = findIdx;
			while (nums[rangeStart] == target && rangeStart >= 0 && rangeStart < static_cast<int>(nums.size())) {
				rangeStart--;
			}
			rangeStart++;
			while (nums[rangeEnd] == target && rangeEnd >= 0 && rangeEnd < static_cast<int>(nums.size())) {
				rangeEnd++;
			}
			rangeEnd--;
			result.push_back(rangeStart);
			result.push_back(rangeEnd);
		}
		else {
			result.push_back(rangeStart);
			result.push_back(rangeEnd);
		}
		return result;
	}

	/*
	You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
	Define a pair (u,v) which consists of one element from the first array and one element from the second array.
	*/
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> result;
		for (int num1 : nums1) {
			for (int num2 : nums2) {
				pair<int, int> p(num1, num2);
				result.push_back(p);
			}
		}
		sort(result.begin(), result.end(), comparePair);
		vector<pair<int, int>> ret;
		k = std::min(k, static_cast<int>(result.size()));
		for (int i = 0; i < k; i++) {
			ret.push_back(result[i]);
		}
		return ret;
	}

	static bool comparePair(pair<int, int>& p1, pair<int, int>& p2) {
		return p1.first + p1.second < p2.first + p2.second;
	}

	vector<string> fizzBuzz(int n) {
		vector<string> result(n);
		int j;
		for (int i = 0; i < n; i++) {
			j = i + 1;
			if (j % 15 == 0) {
				result[i] = "FizzBuzz";
			}
			else if (j % 3 == 0) {
				result[i] = "Fizz";
			}
			else if (j % 5 == 0) {
				result[i] = "Buzz";
			}
			else {
				result[i] = to_string(j);
			}
		}
		return result;
	}

	/*
	Given a string which consists of lowercase or uppercase letters, 
	find the length of the longest palindromes that can be built with those letters.
	*/
	int longestPalindrome(string s) {
		int maxLen = 0;
		int oddCnt = 0;
		vector<int> myTable(58, 0);
		for (char c : s) {
			myTable[c - 'A']++;
		}
		for (int i : myTable) {
			if (i % 2 == 0) {
				maxLen = maxLen + i;
			}
			else {
				maxLen = maxLen + i - 1;
				oddCnt++;
			}
		}
		if (oddCnt > 0) maxLen++;
		return maxLen;
	}

	/*
	The name of a file contains at least a . and an extension.
	The name of a directory or sub-directory will not contain a ..
	*/
	int lengthLongestPath(string input) {
		int result = 0;
		istringstream ss(input);
		unordered_map<int, int> myMap;
		myMap.emplace(0, 0);
		string line = "";
		while (getline(ss, line)) {
			int level = static_cast<int>(line.find_last_of('\t')) + 1;
			int len = static_cast<int>(line.substr(level).length());
			if (level == 0) {
				myMap[level] = len + 1;
			}
			else {
				myMap[level] = myMap[level - 1] + len + 1;
			}
			if (line.find('.') != string::npos) {
				result = max(result, myMap[level] - 1);
			}

		}
		return result;
	}

	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		int start = lower;
		int end = lower;
		string missingRange;
		for (int i : nums) {
			if (i > start) {
				end = i - 1;
				if (start == end) {
					result.push_back(to_string(start));
				}
				else {
					result.push_back(to_string(start) + "->" + to_string(end));
				}
				start = i + 1;
				end = start;
			}
			else {
				start = i + 1;
			}
		}
		if (nums.size() >= 1 && nums.back() < upper) {
			start = nums.back() + 1;
			end = upper;
			if (start == end) {
				result.push_back(to_string(start));
			}
			else {
				result.push_back(to_string(start) + "->" + to_string(end));
			}
		}
		else if (nums.size() == 0) {
			if (lower == upper) {
				result.push_back(to_string(lower));
			}
			else {
				result.push_back(to_string(lower) + "->" + to_string(upper));
			}
		}
		return result;
	}

	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int maxLen = 0;
		int curLen = 0;
		int prevNum = INT_MIN;
		for (int i : nums) {
			if (prevNum == INT_MIN) {
				curLen = 1;
			}
			else if (i - prevNum == 1) {
				curLen++;
			}
			else if (i - prevNum == 0) {
				continue;
			}
			else {
				maxLen = max(maxLen, curLen);
				curLen = 1;
			}
			prevNum = i;
		}
		return max(maxLen, curLen);
	}

	//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
	//You can only see the k numbers in the window. Each time the sliding window moves right by one position.
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> myWindow;

		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			if (!myWindow.empty() && myWindow.front() == i - k) myWindow.pop_front();
			while (!myWindow.empty() && nums[myWindow.back()] < nums[i]) myWindow.pop_back();
			myWindow.push_back(i);
			if (i >= k - 1) result.push_back(nums[myWindow.front()]);
		}
		return result;
	}

	//Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
	string shortestPalindrome(string s) {
		int i = 0;
		if (static_cast<int>(s.size()) == 0) return "";
		for (int j = static_cast<int>(s.size()) - 1; j >= i; j--) {
			if (s[i] == s[j]) i++;
		}

		if (i == static_cast<int>(s.size())) return s;

		string suffix = s.substr(i, string::npos);
		string prefix = string(suffix.rbegin(), suffix.rend());
		string middle = s.substr(0, i);
		return prefix + middle + suffix;
	}

	string frequencySort(string s) {
		map<char, pair<char, int>> myMap;
		vector<pair<char, int>> myVec;
		for (char c : s) {
			if (myMap.find(c) == myMap.end()) {
				pair<char, int> p(c, 1);
				myMap.emplace(c, p);
			}
			else {
				myMap[c].second++;
			}
		}

		for (auto it = myMap.begin(); it != myMap.end(); it++) {
			myVec.push_back(it->second);
		}

		sort(myVec.begin(), myVec.end(), compareCharFreq);
		string result = "";
		for (auto p : myVec) {
			result = result + string(p.second, p.first);
		}
		return result;
	}

	static bool compareCharFreq(pair<char, int> p1, pair<char, int> p2) {
		return p1.second > p2.second;
	}


	/*
	Given a 2D board and a list of words from the dictionary, find all words in the board.
	Each word must be constructed from letters of sequentially adjacent cell,
	where "adjacent" cells are those horizontally or vertically neighboring.
	The same letter cell may not be used more than once in a word.
	*/
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		set<string> tempResult;
		int numRow = static_cast<int>(board.size());
		if (numRow == 0) return result;
		int numCol = static_cast<int>(board[0].size());
		if (numCol == 0) return result;

		Trie myTrie;
		for (string word : words) {
			myTrie.insert(word);
		}

		vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
		for (int x = 0; x < numRow; x++) {
			for (int y = 0; y < numCol; y++) {
				string s = "";
				dfsWordBoard(board, visited, s, x, y, myTrie, tempResult);
			}
		}
		result = vector<string>(tempResult.begin(), tempResult.end());
		return result;

	}

	void dfsWordBoard(vector<vector<char>> board, vector<vector<bool>> visited, string& s, int x, int y, Trie myTrie, set<string>& result) {
		if (x < 0 || x >= static_cast<int>(board.size()) || y < 0 || y >= static_cast<int>(board[0].size())) {

			return;
		}
		if (visited[x][y]) {
			return;
		}
		s = s + string(1, board[x][y]);

		
		if (!myTrie.startsWith(s)) {
			s.pop_back();
			return;
		}
		if (myTrie.search(s)) {
			result.insert(s);
		}
		visited[x][y] = true;
		dfsWordBoard(board, visited, s, x + 1, y, myTrie, result);
		dfsWordBoard(board, visited, s, x - 1, y, myTrie, result);
		dfsWordBoard(board, visited, s, x, y + 1, myTrie, result);
		dfsWordBoard(board, visited, s, x, y - 1, myTrie, result);
		s.pop_back();
		visited[x][y] = false;
		return;
	}

	/*
	Given an integer matrix, find the length of the longest increasing path.
	From each cell, you can either move to four directions: left, right, up or down. 
	You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
	*/
	int longestIncreasingPath(vector<vector<int> >& matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int res = 1, m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());
		vector<vector<int> > dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				res = max(res, dfs(matrix, dp, i, j));
			}
		}
		return res;
	}
	int dfs(vector<vector<int> > &matrix, vector<vector<int> > &dp, int i, int j) {
		if (dp[i][j]) return dp[i][j];
		vector<vector<int> > dirs;
		vector<int> d1;
		d1.push_back(0);
		d1.push_back(1);
		vector<int> d2;
		d2.push_back(0);
		d2.push_back(-1);
		vector<int> d3;
		d3.push_back(1);
		d3.push_back(0);
		vector<int> d4;
		d4.push_back(-1);
		d4.push_back(0);
		dirs.push_back(d1);
		dirs.push_back(d2);
		dirs.push_back(d3);
		dirs.push_back(d4);
		int mx = 1, m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());
		for (auto a : dirs) {
			int x = i + a[0], y = j + a[1];
			if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
			int len = 1 + dfs(matrix, dp, x, y);
			mx = max(mx, len);
		}
		dp[i][j] = mx;
		return mx;
	}

	bool isIncreasing(vector<int> path) {
		if (path.size() < 2) return true;
		return path[path.size() - 1] > path[path.size() - 2];
	}

	/*
	A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
	For 1-byte character, the first bit is a 0, followed by its unicode code.
	For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, 
	followed by n-1 bytes with most significant 2 bits being 10.
	*/
	bool validUtf8(vector<int>& data) {
		for (int i = 0; i < static_cast<int>(data.size()); ++i) {
			if (data[i] < 128) {
				continue;
			}
			else {
				int cnt = 0, val = data[i];
				for (int j = 7; j >= 1; --j) {
					if (val >= pow(2, j)) ++cnt;
					else break;
					val -= static_cast<int>(pow(2, j));
				}
				if (cnt == 1) return false;
				for (int j = i + 1; j < i + cnt; ++j) {
					if (data[j] > 191 || data[j] < 128) return false;
				}
				i += cnt - 1;
			}
		}
		return true;
	}

	//Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
	string addStrings(string num1, string num2) {
		int len1 = static_cast<int>(num1.size());
		int len2 = static_cast<int>(num2.size());
		if (len1 == 0) return num2;
		if (len2 == 0) return num1;
		string result;
		string adder;
		if (len1 >= len2) {
			result = num1;
			adder = num2;
		}
		else {
			result = num2;
			adder = num1;
			int temp = len1;
			len1 = len2;
			len2 = temp;
		}

		int i = len1 - 1;
		int j = len2 - 1;
		int carry = 0;
		while (i >= 0 && j >= 0) {
			int val = result[i] - '0' + adder[j] - '0' + carry;
			carry = val / 10;
			result[i] = static_cast<char>(val % 10 + '0');
			i--;
			j--;
		}
		while (i >= 0 && carry == 1) {
			int val = result[i] - '0' + carry;
			carry = val / 10;
			result[i] = static_cast<char>(val % 10 + '0');
			i--;
		}

		if (carry == 1) {
			return "1" + result;
		}

		return result;
	}

	int arrangeCoins(int n) {
		long k = static_cast<long>(sqrt(n)*sqrt(2)) + 1;
		while (k*k + k > 2 * n) {
			k--;
		}
		return static_cast<int>(k);
	} 

	/*
	Given a sequence of words, check whether it forms a valid word square.
	*/
	bool validWordSquare(vector<string>& words) {
		int i = 0;
		for(string word : words) {
			string vert;
			for(string temp : words) {
				if(i < static_cast<int>(temp.size())) {
					vert = vert + string(1, temp[i]);
				}
			}
			if(word != vert) return false;
			i++;
		}
		return true;
	}

	//Given a set of words (without duplicates), find all word squares you can build from them.
	vector<vector<string>> wordSquares(vector<string>& words) {
		TrieNode* root = new TrieNode();
		int i = 0;
		for(string word : words) {
			TrieNode* node = root;
			for(char c : word) {
				if(node->children[c - 'a'] == NULL) node->children[c - 'a'] = new TrieNode();
				node = node->children[c - 'a'];
				node->indexes.push_back(i);
			}
			i++;
		}
		vector<vector<string>> result;
		vector<string> oneSolution(words[0].size());
		for(string word : words) {
			oneSolution[0] = word;
			dfsWordSquares(words, root, result, oneSolution, 1);
		}
		return result;
	}

	void dfsWordSquares(vector<string>& words, TrieNode* root, vector<vector<string>>& result, vector<string>& oneSolution,  int level) {
		if(level == static_cast<int>(words[0].size())) {
			result.push_back(oneSolution);
			return;
		}
		string str = "";
		for(int i = 0; i < level; i++) {
			str += oneSolution[i][level];
		}

		TrieNode* node = root;
		for(char c : str) {
			if(node->children[c - 'a'] == NULL) return;
			node = node->children[c - 'a'];
		}

		for(int i : node->indexes) {
			oneSolution[level] = words[i];
			dfsWordSquares(words, root, result, oneSolution, level + 1);
		}
	}

	/*
	Given a binary tree, find the length of the longest consecutive sequence path.
	The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
	The longest consecutive path need to be from parent to child (cannot be the reverse).
	*/
	int longestConsecutive(TreeNode* root) {
		if(!root) return 0;
		queue<TreeNode*> currLevel;
		queue<int> currSize;
		currLevel.push(root);
		currSize.push(1);
		int maxSize = 1;

		while(!currLevel.empty()) {
			TreeNode* temp = currLevel.front();
			currLevel.pop();
			int currMax = currSize.front();
			currSize.pop();

			if(temp->left != NULL) {
				int leftSize = currMax;
				if(temp->left->val - temp->val == 1) {
					leftSize++;
					maxSize = max(maxSize, leftSize);
				}
				else {
					leftSize = 1;
				}
				currLevel.push(temp->left);
				currSize.push(leftSize);
			}

			if(temp->right != NULL) {
				int rightSize = currMax;
				if(temp->right->val - temp->val == 1) {
					rightSize++;
					maxSize = max(maxSize, rightSize);
				}
				else {
					rightSize = 1;
				}
				currLevel.push(temp->right);
				currSize.push(rightSize);
			}
		}
		return maxSize;
	}

	/*
	iven a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
	reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. 
	Thus, the itinerary must begin with JFK.
	*/
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> itineray;
		if(tickets.empty()) return itineray;
		unordered_map<string, multiset<string>> fromToMap;
		for(auto ticket : tickets) {
			fromToMap[ticket.first].insert(ticket.second);
		}

		dfsItineray("JFK", fromToMap, itineray);
		vector<string> result(itineray.rbegin(), itineray.rend());
		return result;
	}

	void dfsItineray(string departure, unordered_map<string, multiset<string>>& fromtToMap, vector<string>& itineray) {
		while (!fromtToMap[departure].empty()) {
			string dest = *fromtToMap[departure].begin();
			fromtToMap[departure].erase(fromtToMap[departure].begin());
			dfsItineray(dest, fromtToMap, itineray);
		}
		itineray.push_back(departure);
	}

	/*
	Given a binary tree, return the vertical order traversal of its nodes' values. 
	(ie, from top to bottom, column by column).
	*/
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		map<int, vector<int>> m;
		queue<pair<int, TreeNode*>> q;
		q.push(pair<int, TreeNode*>( 0, root ));
		while (!q.empty()) {
			auto a = q.front(); q.pop();
			m[a.first].push_back(a.second->val);
			if (a.second->left) q.push(pair<int, TreeNode*>( a.first - 1, a.second->left ));
			if (a.second->right) q.push(pair<int, TreeNode*>( a.first + 1, a.second->right ));
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}

	/*
	Given a string that contains only digits 0-9 and a target value, 
	return all possibilities to add binary operators (not unary) +, -, or * between the digits 
	so they evaluate to the target value.
	*/
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		dfsAddOperators(num, target, 0, 0, "", result);
		return result;
	}

	void dfsAddOperators(string num, int target, long long prevNum, long long curNum, string expression, vector<string>& result) {
		if (num.size() == 0 && curNum == target) {
			result.push_back(expression);
			return;
		}
		for (int len = 1; len <= static_cast<int>(num.size()); len++) {
			string newNumString = num.substr(0, len);
			if (newNumString.size() > 1 && newNumString[0] == '0') {
				return;
			}
			string remainNum = num.substr(len, string::npos);
			
			if (expression.size() == 0) {
				dfsAddOperators(remainNum, target, stoll(newNumString), stoll(newNumString), expression + newNumString, result);
			}
			else {
				dfsAddOperators(remainNum, target, stoll(newNumString), curNum + stoll(newNumString), expression + "+" + newNumString, result);
				dfsAddOperators(remainNum, target, -stoll(newNumString), curNum - stoll(newNumString), expression + "-" + newNumString, result);
				dfsAddOperators(remainNum, target, stoll(newNumString)*prevNum, curNum - prevNum + stoll(newNumString)*prevNum, expression + "*" + newNumString, result);
			}
		}
		return;
	}

	/*
	You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
	One envelope can fit into another if and only if both the width and height of one envelope 
	is greater than the width and height of the other envelope.
	*/
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end());
		int n = static_cast<int>(envelopes.size());
		vector<int> dp(n, 1);
		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			result = max(result, dp[i]);
		}
		return result;
	}

	/*
	Given a string which contains only lowercase letters, 
	remove duplicate letters so that every letter appear once and only once. 
	You must make sure your result is the smallest in lexicographical order among all possible results.
	*/
	string removeDuplicateLetters(string s) {
		string result = "0";
		vector<int> asciiTable(26, 0);
		vector<bool> recorded(26, false);
		for (char c : s) asciiTable[c - 'a']++;
		for (char c : s) {
			asciiTable[c - 'a']--;
			if (!recorded[c - 'a']) {
				while (c < result.back() && asciiTable[result.back() - 'a'] > 0) {
					recorded[result.back() - 'a'] = false;
					result.pop_back();
				}
				result.push_back(c);
				recorded[c - 'a'] = true;
			}
		}
		return result.substr(1, string::npos);
	}

	/*
	Given a binary tree, find the maximum path sum.
	For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
	The path must contain at least one node and does not need to go through the root.
	*/
	int maxPathSum(TreeNode* root) {
		int maxSum = INT_MIN;
		calcPathSum(root, maxSum);
		return maxSum;
	}

	int calcPathSum(TreeNode* root, int& maxSum) {
		if(!root) return 0;
		int leftMaxSum = calcPathSum(root->left, maxSum);
		int rightMaxSum = calcPathSum(root->right, maxSum);
		int tempMax = max(root->val, max(root->val + leftMaxSum, root->val + rightMaxSum));
		maxSum = max(maxSum, max(tempMax, root->val + leftMaxSum + rightMaxSum));
		return tempMax;
	}

	/*
	Given a non-empty array of integers, 
	return the third maximum number in this array. 
	If it does not exist, return the maximum number. The time complexity must be in O(n).
	*/
	int thirdMax(vector<int>& nums) {
		set<int, std::greater<int>> mySet;
		for(int num : nums) {
			mySet.insert(num);
		}
		int counter = 0;
		int thirdMaxNum = 0;
		for(auto it = mySet.begin(); it != mySet.end(); it++) {
			counter++;
			if(it == mySet.begin()) {
				thirdMaxNum = *it;
			}
			if(counter == 3) {
				thirdMaxNum = *it;
				break;
			}
		}
		return thirdMaxNum;
	}


	/*
	Given a set of intervals, for each of the interval i, 
	check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, 
	which can be called that j is on the "right" of i.
	For any interval i, you need to store the minimum interval j's index, 
	which means that the interval j has the minimum start point to build the "right" relationship for interval i. 
	If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.
	*/
	vector<int> findRightInterval(vector<Interval>& intervals) {
		int len = static_cast<int>(intervals.size());
		vector<int> result(len, -1);
		vector<int> v;
		unordered_map<int, int> posMap;
		for(int i = 0; i < len; i++) {
			v.push_back(intervals[i].start);
			posMap.emplace(intervals[i].start, i);
		}
		sort(v.begin(), v.end(), std::greater<int>());

		for(int i = 0; i < len; i++) {
			int j = 0;
			while(j < len && intervals[i].end <= v[j]) {
				j++;
			}
			j--;
			
			if(j >= 0) {
				result[i] = posMap[v[j]];
			}
		}

		return result;
	}

	/*
	Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
	*/
	string originalDigits(string s) {
		string result = "";
		vector<int> digitCount(10, 0);
		map<char, int> charMap;
		for(char c : s) {
			if(charMap.find(c) != charMap.end()) {
				charMap[c]++;
			}
			else {
				charMap[c] = 1;
			}
		}
		digitCount[0] = charMap['z'];
		digitCount[2] = charMap['w'];
		digitCount[4] = charMap['u'];
		digitCount[6] = charMap['x'];
		digitCount[8] = charMap['g'];
		digitCount[3] = charMap['h'] - digitCount[8];
		digitCount[5] = charMap['f'] - digitCount[4];
		digitCount[7] = charMap['v'] - digitCount[5];
		digitCount[1] = charMap['o'] - digitCount[0] - digitCount[2] - digitCount[4];
		digitCount[9] = charMap['i'] - digitCount[5] - digitCount[6] - digitCount[8];

		for(int i = 0; i <= 9; i++) {
			if(digitCount[i] >= 1) result += string(digitCount[i], '0' + i);
		}
		
		return result;
	}

	/*
	Given an encoded string, return it's decoded string.
	The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
	Note that k is guaranteed to be a positive integer.
	You may assume that the input string is always valid; 
	No extra white spaces, square brackets are well-formed, etc.
	Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
	For example, there won't be input like 3a or 2[4].
	*/
	string decodeString(string s) {
		string result = "";
		int len = static_cast<int>(s.size());
		if (len < 1) return result;
		stack<int> repeat;
		stack<string> seqStack;
		string oneSeq = "";
		int i = 0;
		while (i < len) {
			//char c = s[i];
			if (s[i] >= '0' && s[i] <= '9') {
				int num = 0;
				while (s[i] >= '0' && s[i] <= '9' && i < len) {
					num = num * 10 + s[i] - '0';
					i++;
				}
				repeat.push(num);
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				oneSeq = "";
				while (s[i] >= 'a' && s[i] <= 'z' && i < len) {
					oneSeq += string(1, s[i]);
					i++;
				}
				seqStack.push(oneSeq);
			}
			else if (s[i] == '[') {
				seqStack.push(string(1, s[i]));
				i++;
			}
			else if (s[i] == ']') {
				oneSeq = "";
				while (seqStack.top() != "[") {
					oneSeq = seqStack.top() + oneSeq;
					seqStack.pop();
				}
				seqStack.pop();
				int repeatNum = repeat.top();
				repeat.pop();
				string temp = oneSeq;
				while (repeatNum > 1) {
					oneSeq += temp;
					repeatNum--;
				}
				seqStack.push(oneSeq);
				i++;
			}
			else {
				i++;
			}
		}
		while (!seqStack.empty())
		{
			result = seqStack.top() + result;
			seqStack.pop();
		}
		return result;
	}

	//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> result;
		if(n < 1) return result;
		return buildBST(1, n);
	}

	vector<TreeNode*> buildBST(int left, int right) {
		vector<TreeNode*> result;
		if(left > right) {
			result.push_back(NULL);
			return result;
		}

		for(int i = left; i <= right; i++) {
			vector<TreeNode*> leftTrees = buildBST(left, i - 1);
			vector<TreeNode*> rightTrees = buildBST(i + 1, right);
			for(TreeNode* leftTree : leftTrees) {
				for(TreeNode* rightTree : rightTrees) {
					TreeNode* root = new TreeNode(i);
					root->left = leftTree;
					root->right = rightTree;
					result.push_back(root);
				}
			}
		}
		return result;
	}

	/*
	For a undirected graph with tree characteristics, we can choose any node as the root. 
	The result graph is then a rooted tree. 
	Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
	Given such a graph, write a function to find all the MHTs and return a list of their root labels.
	*/
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> result;
		if(n == 0) return result;
		if(n == 1) {
			result.push_back(0);
			return result;
		}
		vector<set<int>> graphMap(n, set<int>());
		vector<int> depth(n, 0);
		for(pair<int, int> edge : edges) {
			int node1 = edge.first;
			int node2 = edge.second;
			graphMap[node1].insert(node2);
			depth[node1]++;
			graphMap[node2].insert(node1);
			depth[node2]++;
		}

		vector<int> leaves;
		for(int i = 0; i < n; i++) {
			if(depth[i] == 1) leaves.push_back(i);
		}

		vector<int> nextLeaves;
		
		while(n > 2) {
			n = n - static_cast<int>(leaves.size());
			while(!leaves.empty()) {
				int leave = leaves.back();
				leaves.pop_back();
				for(int i : graphMap[leave]) {
					depth[i]--;
					if(depth[i] == 1) nextLeaves.push_back(i);
				}
			}
			leaves = nextLeaves;
			nextLeaves = vector<int>();
		}
		return leaves;
	}

	/*
	Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
	where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
	Write an algorithm to reconstruct the queue.
	*/
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), compareHeight);
		vector<pair<int, int>> result;
		for(auto person : people) {
			result.insert(result.begin() + person.second, person);
		}
		return result;
	}

	static bool compareHeight(pair<int, int> p1, pair<int, int> p2) {
		if(p1.first == p2.first) {
			return p1.second < p2.second;
		}
		else {
			return p1.first > p2.first;
		}
	}

	/*
	There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
	You begin the journey with an empty tank at one of the gas stations.
	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
	*/
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = static_cast<int>(gas.size());
		if(n == 0) return -1;
		int i = 0;
		while(i < n) {
			int remainGas = 0;
			int currIdx = i;
			remainGas = gas[i] - cost[i];
			if(remainGas < 0) {
				i++;
				continue;
			}		
			currIdx = (currIdx + 1)%n;
			while(currIdx != i) {
				remainGas += gas[currIdx] - cost[currIdx];
				if(remainGas < 0) break;
				currIdx = (currIdx + 1)%n;
			}
			if(currIdx == i) return i;
			else i = max(i+1, currIdx);
		}
		return -1;
	}

	/*
	Write a program to find the nth super ugly number.
	Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
	For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
	*/
	int nthSuperUglyNumber(int n, vector<int>& primes)  {
		vector<int> uglyNums(1, 1);
		vector<int> idx(primes.size(), 0);
		while (static_cast<int>(uglyNums.size()) < n) {
			vector<int> temp;
			int next = INT_MAX;
			for (int i = 0; i < static_cast<int>(primes.size()); i++) {
				int cur = uglyNums[idx[i]] * primes[i];
				next = min(next, cur);
				temp.push_back(cur);
			}
			for (int i = 0; i < static_cast<int>(primes.size()); i++) {
				if (next == temp[i]) idx[i]++;
			}
			uglyNums.push_back(next);
		}
		return uglyNums.back();
	}

	/*
	Additive number is a string whose digits can form additive sequence.
	A valid additive sequence should contain at least three numbers. 
	Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
	*/
	bool isAdditiveNumber(string num) {
		int n = static_cast<int>(num.size());
		for (int len1 = 1; len1 <= n / 2; len1++) {
			for (int len2 = 1; len2 <= (n - len1) / 2; len2++) {
				if (isAdditiveNumber(num.substr(0, len1), num.substr(len1, len2), num.substr(len1 + len2))) return true;
			}
		}
		return false;
	}

	bool isAdditiveNumber(string a, string b, string c) {
		if (a[0] == '0' && a.size() > 1) return false;
		if (b[0] == '0' && b.size() > 1) return false;
		string sum = "";
		int carry = 0;
		int i = static_cast<int>(a.size()) - 1;
		int j = static_cast<int>(b.size()) - 1;
		while (i >= 0 || j >= 0) {
			int d = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
			char dd = static_cast<char>(d % 10 + '0');
			sum = dd + sum;
			carry = d / 10;
		}
		if (carry) sum = "1" + sum;

		if (sum == c) return true;
		if (c.size() <= sum.size() || sum.compare(c.substr(0, sum.size())) != 0) return false;
		return isAdditiveNumber(b, sum, c.substr(sum.size()));
	}

	/*
	Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), 
	return the maximum enemies you can kill using one bomb.
	*/
	int maxKilledEnemies(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int result = 0;
		int rows = static_cast<int>(grid.size());
		int cols = static_cast<int>(grid[0].size());
		vector<vector<int>> v1(rows, vector<int>(cols, 0));
		vector<vector<int>> v2 = v1;
		vector<vector<int>> v3 = v1;
		vector<vector<int>> v4 = v1;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (j == 0) {
					if (grid[i][j] != 'E') v1[i][j] = 0;
					else v1[i][j] = 1;
				}
				else {
					if (grid[i][j] == 'W') v1[i][j] = 0;
					else if (grid[i][j] == '0') v1[i][j] = v1[i][j - 1];
					else v1[i][j] = v1[i][j - 1] + 1;
				}
			}

			for (int j = cols - 1; j >= 0; j--) {
				if (j == cols - 1) {
					if (grid[i][j] != 'E') v2[i][j] = 0;
					else v2[i][j] = 1;
				}
				else {
					if (grid[i][j] == 'W') v2[i][j] = 0;
					else if (grid[i][j] == '0') v2[i][j] = v2[i][j + 1];
					else v2[i][j] = v2[i][j + 1] + 1;
				}
			}
		}

		for (int j = 0; j < cols; j++) {
			for (int i = 0; i < rows; i++) {
				if (i == 0) {
					if (grid[i][j] != 'E') v3[i][j] = 0;
					else v3[i][j] = 1;
				}
				else {
					if (grid[i][j] == 'W') v3[i][j] = 0;
					else if (grid[i][j] == '0') v3[i][j] = v3[i - 1][j];
					else v3[i][j] = v3[i - 1][j] + 1;
				}
			}

			for (int i = rows - 1; i >= 0; i--) {
				if (i == rows - 1) {
					if (grid[i][j] != 'E') v4[i][j] = 0;
					else v4[i][j] = 1;
				}
				else {
					if (grid[i][j] == 'W') v4[i][j] = 0;
					else if (grid[i][j] == '0') v4[i][j] = v4[i + 1][j];
					else v4[i][j] = v4[i + 1][j] + 1;
				}
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == '0') {
					result = max(result, v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]);
				}
			}
		}
		return result;
	}

	/*
	A group of two or more people wants to meet and minimize the total travel distance. 
	You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
	The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
	*/
	int minTotalDistance(vector<vector<int>>& grid) {
		int sum = 0;
		int rows = static_cast<int>(grid.size());
		int cols = static_cast<int>(grid[0].size());
		vector<int> xs;
		vector<int> ys;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1) {
					xs.push_back(j);
					ys.push_back(i);
				}
			}
		}
		sort(xs.begin(), xs.end());
		for (int i : xs) {
			sum += abs(i - xs[xs.size() / 2]);
		}
		for (int i : ys) {
			sum += abs(i - ys[ys.size() / 2]);
		}
		return sum;
	}

	/*
	Given an Android 3x3 key lock screen and two integers m and n,
	count the total number of unlock patterns of the Android lock screen, 
	which consist of minimum of m keys and maximum n keys.
	*/
	int numberOfPatterns(int m, int n) {
		int result = 0;
		vector<vector<int>> jumps(10, vector<int>(10, 0));
		vector<bool> visited(10, false);
		jumps[1][3] = jumps[3][1] = 2;
		jumps[4][6] = jumps[6][4] = 5;
		jumps[7][9] = jumps[9][7] = 8;
		jumps[1][7] = jumps[7][1] = 4;
		jumps[2][8] = jumps[8][2] = 5;
		jumps[3][9] = jumps[9][3] = 6;
		jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
		result += dfsPattern(1, 1, 0, m, n, jumps, visited) * 4;
		result += dfsPattern(2, 1, 0, m, n, jumps, visited) * 4;
		result += dfsPattern(5, 1, 0, m, n, jumps, visited);
		return result;
 	}

	int dfsPattern(int num, int len, int result, int m, int n, vector<vector<int>>& jumps, vector<bool>& visited) {
		if (len >= m) result++;
		len++;
		if (len > n) return result;
		visited[num] = true;
		for (int next = 1; next <= 9; next++) {
			int jump = jumps[num][next];
			if (!visited[next] && (jump == 0 || visited[jump])) {
				result = dfsPattern(next, len, result, m, n, jumps, visited);
			}
		}
		visited[num] = false;
		return result;
	}

	//Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
	bool isReflected(vector<pair<int, int>>& points) {
		if (points.size() < 2) return true;
		unordered_map<int, unordered_set<int>> pointMap;
		int minX = INT_MAX;
		int maxX = INT_MIN;
		for (auto point : points) {
			minX = min(minX, point.first);
			maxX = max(maxX, point.first);
			pointMap[point.first].insert(point.second);
		}
		double mid = static_cast<double>(minX + maxX) / 2;
		for (auto point : points) {
			int reflX = static_cast<int>(mid * 2) - point.first;
			if (pointMap.find(reflX) == pointMap.end() || pointMap[reflX].find(point.second) == pointMap[reflX].end()) return false;
		}
		return true;
	}
	
	/*
	Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
	write a function to check whether these edges make up a valid tree.
	*/
	bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<unordered_set<int>> g(n, unordered_set<int>());
		unordered_set<int> visited;
		queue<int> q;
		q.push(0);
		visited.insert(0);
		for (auto edge : edges) {
			g[edge.first].insert(edge.second);
			g[edge.second].insert(edge.first);
		}
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			
			for (int a : g[t]) {
				if (visited.find(a) != visited.end()) return false;
				q.push(a);
				visited.insert(a);
				g[a].erase(t);
			}
		}
		return static_cast<int>(visited.size()) == n;
	}

	/*
	Any live cell with fewer than two live neighbors dies, as if caused by under-population.
	Any live cell with two or three live neighbors lives on to the next generation.
	Any live cell with more than three live neighbors dies, as if by over-population..
	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
	0: dead -> dead
	1: live -> live
	2: live -> dead
	3: dead -> live
	*/
	void gameOfLife(vector<vector<int>>& board) {
		int rows = static_cast<int>(board.size());
		if (rows == 0) return;
		int cols = static_cast<int>(board[0].size());
		if (cols == 0) return;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int stat = checkNeighbor(board, i, j);
				if (stat == 2) continue;
				if (stat == 3) board[i][j] = board[i][j] == 0 ? 3 : 1;
				else board[i][j] = board[i][j] == 0 ? 0 : 2;
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				board[i][j] = board[i][j] % 2;
			}
		}
	}

	int checkNeighbor(vector<vector<int>>& board, int x, int y) {
		int count = 0;
		int row = static_cast<int>(board.size());
		int col = static_cast<int>(board[0].size());
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i < 0 || i >= row || j < 0 || j >= col || (i == x && j == y)) continue;
				if (board[i][j] == 1 || board[i][j] == 2) count++;
			}
		}
		return count;
	}

	/*
	Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
	If the fractional part is repeating, enclose the repeating part in parentheses
	*/
	string fractionToDecimal(int numerator, int denominator) {
		int s1 = numerator >= 0 ? 1 : -1;
		int s2 = denominator >= 0 ? 1 : -1;
		long long num = abs((long long)numerator);
		long long den = abs((long long)denominator);
		long long out = num / den;
		long long rem = num % den;
		unordered_map<long long, int> m;
		string res = to_string(out);
		if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
		if (rem == 0) return res;
		res += ".";
		string s = "";
		int pos = 0;
		while (rem != 0) {
			if (m.find(rem) != m.end()) {
				s.insert(m[rem], "(");
				s += ")";
				return res + s;
			}
			m[rem] = pos;
			s += to_string((rem * 10) / den);
			rem = (rem * 10) % den;
			++pos;
		}
		return res + s;
	}
	
	/*
	Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
	the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
	Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
	Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
	*/
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> result;
		int m = static_cast<int>(matrix.size());
		if(m == 0) return result;
		int n = static_cast<int>(matrix[0].size());
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		for(int i = 0; i < m; i++) {
			dfsWaterFlow(matrix, pacific, INT_MIN, m, n, i, 0);
			dfsWaterFlow(matrix, atlantic, INT_MIN, m, n, i, n - 1);
		}
		for(int j = 0; j < n; j++) {
			dfsWaterFlow(matrix, pacific, INT_MIN, m, n, 0, j);
			dfsWaterFlow(matrix, atlantic, INT_MIN, m, n, m - 1, j);
		}
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(pacific[i][j] && atlantic[i][j]) {
					result.push_back(pair<int, int>(i, j));
				}
			}
		}
		return result;
	}

	void dfsWaterFlow(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int preHight, int rows, int cols, int i, int j) {
		if(i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || matrix[i][j] < preHight) return;
		visited[i][j] = true;
		dfsWaterFlow(matrix, visited, matrix[i][j], rows, cols, i - 1, j);
		dfsWaterFlow(matrix, visited, matrix[i][j], rows, cols, i + 1, j);
		dfsWaterFlow(matrix, visited, matrix[i][j], rows, cols, i, j - 1);
		dfsWaterFlow(matrix, visited, matrix[i][j], rows, cols, i, j + 1);
	}

	/*
	Given a non-negative integer num represented as a string, 
	remove k digits from the number so that the new number is the smallest possible.
	*/
	string removeKdigits(string num, int k) {
		string result = "";
		int n = static_cast<int>(num.size());
		int keep = n - k;
		for (char c : num) {
			while (k && result.size() && result.back() > c) {
				result.pop_back();
				k--;
			}
			result.push_back(c);
		}
		result.resize(keep);
		while (!result.empty() && result[0] == '0') result.erase(result.begin());
		return result.empty() ? "0" : result;
	}

	/*
	There is a new alien language which uses the latin alphabet. However, 
	the order among letters are unknown to you. 
	You receive a list of words from the dictionary, 
	where words are sorted lexicographically by the rules of this new language. 
	Derive the order of letters in this language.
	*/
	string alienOrder(vector<string>& words) {
		set<pair<char, char>> charOder;
		unordered_set<char> chars;
		unordered_map<char, int> charCount;
		queue<char> q;
		string result = "";
		int n = static_cast<int>(words.size());
		for(string word : words) {
			chars.insert(word.begin(), word.end());
		}
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0; j < min(static_cast<int>(words[i].size()), static_cast<int>(words[i+1].size())); j++) {
				if(words[i][j] != words[i+1][j]) {
					charOder.insert(make_pair(words[i][j], words[i+1][j]));
					break;
				}
			}
		}
		for(pair<char, char> p : charOder) charCount[p.second]++;
		for(char c : chars) {
			if(charCount[c] == 0) {
				q.push(c);
				result += c;
			}
		}
		while(!q.empty()) {
			char lead = q.front();
			q.pop();
			for(auto p : charOder) {
				if(p.first == lead) {
					charCount[p.second]--;
					if(charCount[p.second] == 0) {
						q.push(p.second);
						result += p.second;
					}
				}
			}
		}
		return result.size() == chars.size() ? result : "";
	}


	/*
	Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
	You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
	*/
	bool repeatedSubstringPattern(string str)  {
		int n = static_cast<int>(str.size());
		if(n == 0) return false;
		for(int subLen = 1; subLen < n/2 + 1; subLen++) {
			if(n%subLen == 0) {
				string newStr = "";
				for(int i = 0; i < n/subLen; i++) {
					newStr += str.substr(0, subLen);
				}
				if(str == newStr) return true;
			}
		}
		return false;
	}

	/*
	Given n points in the plane that are all pairwise distinct, 
	a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
	*/
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int result = 0;
		int n = static_cast<int>(points.size());
		for(int i = 0; i < n; i++) {
			unordered_map<int, int> distMap;
			for(int j = 0; j < n; j++) {
				if(i == j) continue;
				int dist = (points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second);
				if(distMap.find(dist) == distMap.end()) distMap.insert(pair<int, int>(dist, 1));
				else distMap[dist]++;
			}
			for(pair<int, int> p : distMap) {
				result += p.second*(p.second - 1);
			}
		}
		return result;
	}

	/*
	Given a non-empty integer array of size n, 
	find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
	*/
	int minMoves(vector<int>& nums) {
		//int result = 0;
		int sum = 0;
		int minNum = INT_MAX;
		for(int num : nums) {
			minNum = min(minNum, num);
			sum += num;
		}
		return sum - static_cast<int>(minNum*nums.size());
	}

	int minMoves2(vector<int>& nums) {
		if (nums.empty()) return 0;
		sort(nums.begin(), nums.end());
		int n = static_cast<int>(nums.size());
		int m = nums[nums.size() / 2];
		int result = 0;
		for (int i = 0; i < n; i++) {
			result += abs(m - nums[i]);
		}
		return result;
	}

	/*
	Assume you are an awesome parent and want to give your children some cookies. 
	But, you should give each child at most one cookie. Each child i has a greed factor gi, 
	which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, 
	we can assign the cookie j to the child i, 
	and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
	*/
	int findContentChildren(vector<int>& g, vector<int>& s)  {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int nG = static_cast<int>(g.size());
		int nS = static_cast<int>(s.size());
		int satis = 0;
		int j = 0;
		for(int i = 0; i < nG; i++) {
			while(j < nS && s[j] < g[i]) {
				j++;
			}
			if(j < nS) {
				satis++;
				j++;
			}
		}
		return satis;
	}

	/*
	each of the rows and columns are sorted in ascending order
	find the kth smallest element in the matrix.
	Note that it is the kth smallest element in the sorted order, not the kth distinct element.
	*/
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> pq;
		int n = static_cast<int>(matrix.size());
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				pq.push(matrix[i][j]);
				if(static_cast<int>(pq.size()) > k) pq.pop();
			}
		}
		return pq.top();
	}

	/*
	There is a fence with n posts, each post can be painted with one of the k colors.
	You have to paint all the posts such that no more than two adjacent fence posts have the same color.
	Return the total number of ways you can paint the fence.
	*/
	int numWays(int n, int k) {
		if(n == 0) return 0;
		int same = 0; 
		int diff = k;
		for(int i = 2; i <= n; i++) {
			int temp = diff;
			diff = (k - 1)*(same + diff);
			same = temp;
		}
		return same + diff;
	}

	//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int result = 0;
		int left = 0;
		unordered_map<char, int> charCount;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			charCount[s[i]]++;
			while (charCount.size() > 2) {
				if (--charCount[s[left]] == 0) charCount.erase(s[left]);
				left++;
			}
			result = max(result, i - left + 1);
		}
		return result;
	}

	//Longest Substring with At Most K Distinct Characters
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int result = 0;
		int left = 0;
		unordered_map<char, int> charCount;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			charCount[s[i]]++;
			while (static_cast<int>(charCount.size()) > k) {
				if (--charCount[s[left]] == 0) charCount.erase(s[left]);
				left++;
			}
			result = max(result, i - left + 1);
		}
		return result;
	}

	/*
	You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
	You can only move up, down, left and right.
	Each 0 marks an empty land which you can pass by freely.
	Each 1 marks a building which you cannot pass through.
	Each 2 marks an obstacle which you cannot pass through.
	*/
	int shortestDistance(vector<vector<int>>& grid) {
		int result = INT_MAX;
		int rows = static_cast<int>(grid.size());
		int cols = static_cast<int>(grid[0].size());
		int visitMarker = 0;
		vector<vector<int>> sum(rows, vector<int>(cols, 0));
		vector<pair<int, int>> dirs;
		dirs.push_back(make_pair(1, 0));
		dirs.push_back(make_pair(-1, 0));
		dirs.push_back(make_pair(0, 1));
		dirs.push_back(make_pair(0, -1));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1) {
					result = INT_MAX;
					vector<vector<int>> dist(rows, vector<int>(cols, 0));
					queue<pair<int, int>> q;
					q.push(pair<int, int>(i, j));
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (auto dir : dirs) {
							int newX = x + dir.first;
							int newY = y + dir.second;
							if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == visitMarker) {
								grid[newX][newY]--;
								q.push(pair<int, int>(newX, newY));
								dist[newX][newY] = dist[x][y] + 1;
								sum[newX][newY] += dist[newX][newY];
								result = min(result, sum[newX][newY]);
							}
						}
					}
					visitMarker--;
				}
			}
		}
		return result == INT_MAX ? -1 : result;
	}
	
	/*
	Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
	You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
	Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
	*/
	int maxCoins(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		for(int len = 1; len <= n; len++) {
			for(int left = 1; left <= n - len + 1; left++) {
				int right = left + len - 1;
				for(int k = left; k <= right; k++) {
					dp[left][right] = max(dp[left][right], nums[left - 1]*nums[k]*nums[right + 1] + dp[left][k-1] + dp[k+1][right]);
				}
			}
		}
		return dp[1][n];
	}

	/*
	Given two arrays of length m and n with digits 0-9 representing two numbers. 
	Create the maximum number of length k <= m + n from digits of the two. 
	The relative order of the digits from the same array must be preserved. 
	Return an array of the k digits. You should try to optimize your time and space complexity.
	*/
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int n1 = static_cast<int>(nums1.size());
		int n2 = static_cast<int>(nums2.size());
		vector<int> result;
		for(int i = max(0, k - n2); i <= min(k, n1); i++) {
			vector<int> v1 = maxVector(nums1, i);
			vector<int> v2 = maxVector(nums2, k - i);
			result = max(result, mergerVector(v1, v2));
		}
		return result;
	}

	vector<int> maxVector(vector<int> nums, int k) {
		int drop = static_cast<int>(nums.size()) - k;
		vector<int> result;
		for(int num : nums) {
			while(drop && result.size() && result.back() < num) {
				result.pop_back();
				drop--;
			}
			result.push_back(num);
		}
		result.resize(k);
		return result;
	}

	vector<int> mergerVector(vector<int> nums1, vector<int> nums2) {
		vector<int> result;
		while(nums1.size() + nums2.size()) {
			vector<int> &tmp = nums1 > nums2 ? nums1 : nums2;
			result.push_back(tmp[0]);
			tmp.erase(tmp.begin());
		}
		return result;
	}

	/*
	Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.
	Each rectangle is represented as a bottom-left point and a top-right point. 
	For example, a unit square is represented as [1,1,2,2]. 
	(coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).
	*/
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		unordered_set<string> points;
		int minX = INT_MAX;
		int maxX = INT_MIN;
		int minY = INT_MAX;
		int maxY = INT_MIN;
		int area = 0;
		for (vector<int> rectangle : rectangles) {
			minX = min(minX, rectangle[0]);
			minY = min(minY, rectangle[1]);
			maxX = max(maxX, rectangle[2]);
			maxY = max(maxY, rectangle[3]);
			area += (rectangle[2] - rectangle[0])*(rectangle[3] - rectangle[1]);
			string p1 = to_string(rectangle[0]) + "_" + to_string(rectangle[1]);
			string p2 = to_string(rectangle[0]) + "_" + to_string(rectangle[3]);
			string p3 = to_string(rectangle[2]) + "_" + to_string(rectangle[1]);
			string p4 = to_string(rectangle[2]) + "_" + to_string(rectangle[3]);
			if (points.count(p1)) points.erase(p1);
			else points.insert(p1);
			if (points.count(p2)) points.erase(p2);
			else points.insert(p2);
			if (points.count(p3)) points.erase(p3);
			else points.insert(p3);
			if (points.count(p4)) points.erase(p4);
			else points.insert(p4);
		}
		string v1 = to_string(minX) + "_" + to_string(minY);
		string v2 = to_string(minX) + "_" + to_string(maxY);
		string v3 = to_string(maxX) + "_" + to_string(minY);
		string v4 = to_string(maxX) + "_" + to_string(maxY);
		if (!points.count(v1) || !points.count(v2) || !points.count(v3) || !points.count(v4) || points.size() != 4) return false;
		return area == (maxX - minX)*(maxY - minY);
	}

	/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1, 
	compute how much water it is able to trap after raining.
	*/
	int trap(vector<int>& height) {
		int n = static_cast<int>(height.size());
		int result = 0;
		int left = 0;
		int right = 0;
		int level = 0;
		int i = 1;
		while(i < n - 1) {
			if (height[i] > height[i - 1] || height[i] > height[i + 1]) {
				i++;
				continue;
			}
			for (left = i - 1; left > 0; left--) {
				if (height[left] > height[left - 1]) break;
			}
			right = i + 1;
			for (int j = i + 1; j < n; j++) {
				if (height[j] >= height[right]) {
					right = j;
					if (height[right] >= height[left]) break;
				}
			}
			level = min(height[left], height[right]);
			for (int j = left + 1; j < right; j++) {
				if (level - height[j] > 0) result += (level - height[j]);
			}
			i = right;
		}
		return result;
	}

	/*
	Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, 
	compute the volume of water it is able to trap after raining.
	*/
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.empty()) return 0;
		int m = static_cast<int>(heightMap.size());
		int n = static_cast<int>(heightMap[0].size());
		int result = 0;
		int level = INT_MIN;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> buildings;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		vector<pair<int, int>> dirs;
		dirs.push_back(pair<int, int>(1, 0));
		dirs.push_back(pair<int, int>(-1, 0));
		dirs.push_back(pair<int, int>(0, 1));
		dirs.push_back(pair<int, int>(0, -1));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
					buildings.push(pair<int, int>(heightMap[i][j], i*n + j));
					visited[i][j] = true;
				}
			}
		}

		while (!buildings.empty()) {
			pair<int, int> lowest = buildings.top();
			buildings.pop();
			int height = lowest.first;
			int row = lowest.second / n;
			int col = lowest.second % n;
			level = max(level, height);
			for (pair<int, int> dir : dirs) {
				int x = row + dir.first;
				int y = col + dir.second;
				if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
				visited[x][y] = true;
				if (heightMap[x][y] < level) result += level - heightMap[x][y];
				buildings.push(make_pair(heightMap[x][y], x*n + y));
			}
		}
		return result;
	}

	/*
	You are given an integer array nums and you have to return a new counts array. 
	The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
	*/
	vector<int> countSmaller(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		vector<int> sorted;
		vector<int> result(n);
		for (int i = n - 1; i >= 0; i--) {
			int left = 0;
			int right = static_cast<int>(sorted.size());
			while (left < right) {
				int mid = (left + right) / 2;
				if (sorted[mid] >= nums[i]) right = mid;
				else left = mid + 1;
			}
			result[i] = right;
			sorted.insert(sorted.begin() + right, nums[i]);
		}
		return result;
	}

	int islandPerimeter(vector<vector<int>>& grid) {
		int rows = static_cast<int>(grid.size());
		if (rows == 0) return 0;
		int cols = static_cast<int>(grid[0].size());
		if (cols == 0) return 0;
		int result = 0;
		
		vector<pair<int, int>> dirs;
		dirs.push_back(pair<int, int>(1, 0));
		dirs.push_back(pair<int, int>(-1, 0));
		dirs.push_back(pair<int, int>(0, 1));
		dirs.push_back(pair<int, int>(0, -1));

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 1) result += unitPerimeter(grid, dirs, i, j);
			}
		}
		return result;
	}

	int unitPerimeter(vector<vector<int>>& grid, vector<pair<int, int>>& dirs, int i, int j) {
		int result = 0;
		int rows = static_cast<int>(grid.size());
		int cols = static_cast<int>(grid[0].size());
		for (pair<int, int> dir : dirs) {
			int x = i + dir.first;
			int y = j + dir.second;
			if (x < 0 || x >= rows || y < 0 || y >= cols) result++;
			else if (grid[x][y] == 0) result++;
		}
		return result;
	}

	/*
	Given a positive integer n, 
	find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
	*/
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; i + j*j <= n; j++) {
				dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
			}
		}
		return dp.back();
	}

	/*
	Given a matrix of m x n elements (m rows, n columns), 
	return all elements of the matrix in spiral order.
	*/
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int dirIdx = 0;
		int top = 0;
		int bottom = static_cast<int>(matrix.size());
		if (bottom == 0) return result;
		int left = 0;
		int right = static_cast<int>(matrix[0].size());
		if (right == 0) return result;
		int numElem = bottom * right;
		while (numElem > 0) 
		{
			if (dirIdx == 0) {
				for (int i = left; i < right; i++) {
					result.push_back(matrix[top][i]);
					numElem--;
				}
				top++;
			}
			else if (dirIdx == 1) {
				for (int i = top; i < bottom; i++) {
					result.push_back(matrix[i][right-1]);
					numElem--;
				}
				right--;
			}
			else if (dirIdx == 2) {
				for (int i = right - 1; i >= left; i--) {
					result.push_back(matrix[bottom-1][i]);
					numElem--;
				}
				bottom--;
			}
			else {
				for (int i = bottom - 1; i >= top; i--) {
					result.push_back(matrix[i][left]);
					numElem--;
				}
				left++;
			}
			dirIdx = (dirIdx + 1) % 4;

		}
		return result;
	}

	/*
	Given a rows x cols screen and a sentence represented by a list of words, find how many times the given sentence can be fitted on the screen.
	A word cannot be split into two lines.
	The order of words in the sentence must remain unchanged.
	Two consecutive words in a line must be separated by a single space.
	Total words in the sentence won't exceed 100.
	Length of each word won't exceed 10.
	*/
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		string all = "";
		for(string word : sentence) all = all + word + " ";
		int result = 0;
		int idx = 0;
		int n = static_cast<int>(sentence.size());
		int totLen = static_cast<int>(all.size());
		for(int i = 0; i < rows; i++) {
			int remainCols = cols;
			while(remainCols > 0) {
				if(static_cast<int>(sentence[idx].size()) <= remainCols) {
					remainCols = remainCols - static_cast<int>(sentence.size());
					if(remainCols > 0) remainCols--;
					idx++;
					if(idx >= n) {
						result = result + 1 + (remainCols/totLen);
						remainCols = remainCols%totLen;
						idx = 0;
					}
				}
				else break;
			}
		}
		return result;
	}

	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int len = 1; len < n; len++) {
			for (int start = 1; start + len <= n; start++) {
				dp[start][start + len] = INT_MAX;
				for (int i = start; i < start + len; i++) {
					dp[start][start + len] = min(dp[start][start + len], i + max(dp[start][i - 1], dp[i + 1][start + len]));
				}
			}
		}
		return dp[1][n];
	}

	
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = static_cast<int>(nums.size());
		vector<int> dp(n, 1);
		vector<int> parent(n, -1);
		vector<int> result;
		int max_len = 0;
		int max_idx = -1;
		for(int i = 0; i < n; i++) {
			for(int j = i - 1; j >= 0; j--) {
				if(nums[i]%nums[j] == 0 && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					parent[i] = j;
				}
			}
			if(dp[i] > max_len) {
				max_len = dp[i];
				max_idx = i;
			}
		}
		while(max_idx != -1) {
			result.push_back(nums[max_idx]);
			max_idx = parent[max_idx];
		}
		return result;
	}

	/*
	Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, 
	empty slots are represented with '.'s. You may assume the following rules:
	*/
	int countBattleships(vector<vector<char>>& board) {
		int rows = static_cast<int>(board.size());
		if (rows == 0) return 0;
		int cols = static_cast<int>(board[0].size());
		if (cols == 0) return 0;
		int result = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) continue;
				result++;
			}
		}
		return result;
	}

	/*
	Given a list of strings which contains only lowercase alphabets, 
	group all strings that belong to the same shifting sequence.
	*/
	vector<vector<string>> groupStrings(vector<string>& strings) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> group;
		for (string s : strings) {
			string key = "";
			for (char c : s) {
				key += to_string((c - s[0] + 26) % 26) + " ";
			}
			group[key].push_back(s);
		}
		for (auto p : group) {
			result.push_back(p.second);
		}
		return result;
	}

	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> result;
		vector<pair<int, int>> height;
		multiset<int> m;
		int pre = 0;
		int cur = 0;
		for (vector<int> building : buildings) {
			height.push_back(make_pair(building[0], -building[2]));
			height.push_back(make_pair(building[1], building[2]));
		}
		sort(height.begin(), height.end());
		m.insert(0);
		for (auto h : height) {
			if (h.second < 0) m.insert(-h.second);
			else m.erase(m.find(h.second));
			cur = *m.rbegin();
			if (cur != pre) {
				result.push_back(make_pair(h.first, cur));
				pre = cur;
			}
		}
		return result;
	}

	int findMaximumXOR(vector<int>& nums) {
		int result = 0;
		int mask = 0;
		for(int i = 31; i >= 0; i--) {
			mask = mask|(1<<i);
			set<int> s;
			for(int num : nums) {
				s.insert(num&mask);
			}
			//assume position i in result is 1
			int t = result | (1<<i);
			// if prefix_another ^ prefix = t
			// then prefix_another = t ^ prefix
			for(int prefix : s) {
				//given prefix, if prefix_another exists, position i in result must be 1
				if(s.find(t^prefix) != s.end()) {
					result = t;
					break;
				}
			}
		}
		return result;
	}

	//Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int result = 0;
		long long sum = 0;
		multiset<long long> sums;
		sums.insert(0);
		for (int i = 0; i < static_cast<int>(nums.size()); i++) {
			sum += nums[i];
			result += static_cast<int>(distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower)));
			sums.insert(sum);
		}
		return result;
	}

	/*
	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle.
	*/
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> oneSolution;
		if(n == 0) return result;
		vector<int> rowToCol(n, -1);
		dfsNQueens(result, oneSolution, rowToCol, n, 0);
		return result;
	}

	void dfsNQueens(vector<vector<string>>& result, vector<string>& oneSolution, vector<int>& rowToCol, int n, int cur) {
		if(cur == n) {
			result.push_back(oneSolution);
			return;
		}
		for(int colPos = 0; colPos < n; colPos++) {
			rowToCol[cur] = colPos;
			bool validPos = true;
			for(int preRow = 0; preRow < cur; preRow++) {
				if(rowToCol[cur] == rowToCol[preRow] || cur - preRow == abs(rowToCol[cur] - rowToCol[preRow])) validPos = false;
			}
			if(validPos) {
				string oneRow = string(n, '.');
				oneRow[colPos] = 'Q';
				oneSolution.push_back(oneRow);
				dfsNQueens(result, oneSolution, rowToCol, n, cur+1);
				oneSolution.pop_back();
			}
		}
	}

	//instead outputting board configurations, return the total number of distinct solutions.
	int totalNQueens(int n) {
		vector<vector<string>> result;
		vector<string> oneSolution;
		if(n == 0) return 0;
		vector<int> rowToCol(n, -1);
		dfsNQueens(result, oneSolution, rowToCol, n, 0);
		return static_cast<int>(result.size());
	}

	/*
	An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
	The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. 
	Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
	*/
	int minArea(vector<vector<char>>& image, int x, int y)  {
		int left = y, right = y, up = x, down = x;
        dfs(image, x, y, left, right, up, down);
        return (right - left + 1) * (down - up + 1);
	}

	void dfs(vector<vector<char>> &image, int x, int y, int &left, int &right, int &up, int &down) {
        if (x < 0 || x >= static_cast<int>(image.size()) || y < 0 || y >= static_cast<int>(image[0].size()) || image[x][y] != '1') return;
        left = min(left, y); 
        right = max(right, y);
        up = min(up, x);
        down = max(down, x);
        image[x][y] = '2';
        dfs(image, x + 1, y, left, right, up, down);
        dfs(image, x - 1, y, left, right, up, down);
        dfs(image, x, y + 1, left, right, up, down);
        dfs(image, x, y - 1, left, right, up, down);
    }


	/*
	Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
	All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "";
	*/
	string rearrangeString(string str, int k) {
		if (k == 0) return str;
        string res;
        int len = (int)str.size();
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (auto a : str) ++m[a];
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push(make_pair(it->second, it->first));
        }
        while (!q.empty()) {
            vector<pair<int, int>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (q.empty()) return "";
                auto t = q.top(); q.pop();
                res.push_back(t.second);
                if (--t.first > 0) v.push_back(t);
                --len;
            }
            for (auto a : v) q.push(a);
        }
        return res;
	}

	//Given two integers x and y, calculate the Hamming distance.
	int hammingDistance(int x, int y) {
		int temp = x^y;
		int result = 0;
		for(int i = 0; i < 32; i++) {
			if((temp & 1) == 1) result++;
			temp = temp>>1;
		}
		return result;
	}

	/*
	design a standard heater with fixed warm radius to warm all the houses.
	you are given positions of houses and heaters on a horizontal line, 
	find out minimum radius of heaters so that all houses could be covered by those heaters.
	*/
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		int minRadius = 0;
		for(int i = 0; i < static_cast<int>(houses.size()); i++) {
			//Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
			auto lower = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			int currRadius = INT_MAX;

			//if such heater exists, update the currRadius to cover current house
			if(lower != heaters.end()) currRadius = *lower - houses[i];

			//if current heater is not the first one, check if current house can be covered by previous heater
			if(lower != heaters.begin()) {
				auto preHeater = lower - 1;
				currRadius = min(currRadius, houses[i] - *preHeater);
			}
			minRadius = max(currRadius, minRadius);
		}
		return minRadius;
	}

	int findSubstringInWraproundString(string p) {
		vector<int> endingCount(26, 0);
		int len = 0;
		for(int i = 0; i < static_cast<int>(p.size()); i++) {
			if(i > 0 && (p[i] - p[i-1] == 1 || p[i] - p[i-1] == -25)) {
				len++;
			}
			else len = 1;
			endingCount[p[i] - 'a'] = max(endingCount[p[i] - 'a'], len);
		}
		int result = 0;
		for(int cnt : endingCount) result += cnt;
		return result;
	}

	bool find132pattern(vector<int>& nums) {
		int last = INT_MIN;
		stack<int> s;
		int n = static_cast<int>(nums.size());
		for(int i = n - 1; i >= 0; i--) {
			if(nums[i] < last) return true;
			else {
				while(!s.empty() && nums[i] > s.top()) {
					last = s.top();
					s.pop();
				}
			}
			s.push(nums[i]);
		}
		return false;
	}

	int minMutation(string start, string end, vector<string>& bank) {
		queue<string> toVisit;
		unordered_set<string> dict(bank.begin(), bank.end());
		int dist = 0;
		
		if(dict.find(end) == dict.end()) return -1;
		toVisit.push(start);
		dict.insert(start);
		dict.insert(end);
		while(!toVisit.empty()) {
			int n = static_cast<int>(toVisit.size());
			for(int i = 0; i < n; i++) {
				string str = toVisit.front();
				toVisit.pop();
				if(str == end) return dist;
				changeAWord(str, dict, toVisit);
			}
			dist++;
		}
		return -1;
	}

	void changeAWord(string word, unordered_set<string>& dict, queue<string>& toVisit) {
		dict.erase(word);
		for(int i = 0; i < static_cast<int>(word.size()); i++) {
			char currChar = word[i];
			for(char c : string("abcdefghijklmnopqrstuvwxyz")) {
				word[i] = c;
				if(dict.find(word) != dict.end()) {
					toVisit.push(word);
					dict.erase(word);
				}
			}
			word[i] = currChar;
		}
	}

	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		queue<string> toVisit;
		int dist = 1;
		if(wordList.find(endWord) == wordList.end()) return 0;
		toVisit.push(beginWord);
		wordList.insert(beginWord);
		wordList.insert(endWord);
		while(!toVisit.empty()) {
			int n = static_cast<int>(toVisit.size());
			for(int i = 0; i < n; i++) {
				string str = toVisit.front();
				toVisit.pop();
				if(str == endWord) return dist;
				changeAWord(str, wordList, toVisit);
			}
			dist++;
		}
		return 0;
	}

	/*
	Longest Substring with At Least K Repeating Characters
	*/
	int longestSubstring(string s, int k) {
		unordered_map<char, int> m;
		for(char c : s) {
			m[c]++;
		}
		unordered_set<char> splitSet;
		for(auto p : m) {
			if(p.second < k) splitSet.insert(p.first);
		}
		if(splitSet.empty()) return static_cast<int>(s.size());
		int result = 0;
		int left = 0;
		int right = 0;
		while(right < static_cast<int>(s.size())) {
			if(splitSet.find(s[right]) != splitSet.end()) {
				if(right != left) result = max(result, longestSubstring(s.substr(left, right - left), k));
				left = right + 1;
			}
			right++;
		}
		if(right != left) result = max(result, longestSubstring(s.substr(left, right - left), k));
		return result;
	}

	//Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
	int countSegments(string s) {
		istringstream ss(s);
		string line = "";
		int result = 0;
		while (getline(ss, line, ' ')) {
			if (line.size() > 0) result++;
		}
		return result;
	}

	void rotate(vector<vector<int>>& matrix) {
		int m = static_cast<int>(matrix.size());
		if (m == 0) return;
		int n = static_cast<int>(matrix[0].size());
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m / 2; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][m - j - 1];
				matrix[i][m - j - 1] = temp;
			}
		}
	}

	int findMaxConsecutiveOnes(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		if (n == 0) return 0;
		int result = 0;
		int flipLim = 0;
		queue<int> zeroIndex;
		int low = 0;
		int high = 0;
		for (high = 0; high < n; high++) {
			if (nums[high] == 0) zeroIndex.push(high);
			while (static_cast<int>(zeroIndex.size()) > flipLim) {
				low = zeroIndex.front() + 1;
				zeroIndex.pop();
			}
			result = max(result, high - low + 1);
		}
		return result;
	}

	//Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
	int findMaxConsecutiveOnes2(vector<int>& nums) {
		int n = static_cast<int>(nums.size());
		if (n == 0) return 0;
		int result = 0;
		int zeroCount = 0;;
		int flipLim = 1;
		int low = 0;
		int high = 0;
		for (high = 0; high < n; high++) {
			if (nums[high] == 0) zeroCount++;
			while (zeroCount > flipLim) {
				if (nums[low++] == 0) {
					zeroCount--;
				}
			}
			result = max(result, high - low + 1);
		}
		return result;
	}


};

#endif
