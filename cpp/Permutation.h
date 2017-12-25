#pragma once
class Permutation
{
public:
	Permutation();
	~Permutation();

	//Given a collection of distinct numbers, return all possible permutations.
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> allPer;
		if (nums.empty()) return allPer;
		allPer.push_back(vector<int>(1, nums[0]));

		for (int i = 1; i<static_cast<int>(nums.size()); i++) {
			int n = static_cast<int>(allPer.size());
			for (int j = 0; j<n; j++) {
				for (int k = 0; k<static_cast<int>(allPer[j].size()); k++) {
					vector<int> per = allPer[j];
					per.insert(per.begin() + k, nums[i]);
					allPer.push_back(per);
				}
				allPer[j].push_back(nums[i]);
			}
		}
		return allPer;
	}

	//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.empty()) return result;
		result.push_back(vector<int>());

		for (int element : nums) {
			set<vector<int>> permSet;
			for (vector<int> onePerm : result) {
				for (int j = 0; j <= static_cast<int>(onePerm.size()); j++) {
					vector<int> temp = onePerm;
					temp.insert(temp.begin() + j, element);
					permSet.insert(temp);
				}
			}
			result = vector<vector<int>>(permSet.begin(), permSet.end());
		}
		return result;
	}

	/*
	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
	The replacement must be in-place, do not allocate extra memory.
	Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
	1,2,3 -> 1,3,2
	3,2,1 -> 1,2,3
	1,1,5 -> 1,5,1
	*/
	void nextPermutation(vector<int>& nums) {
		int len = static_cast<int>(nums.size());
		if(len < 2) return;
		int index1 = -1;
		int index2 = -1;
		for(int i = len - 2; i >=0; i--) {
			if(nums[i] < nums[i+1]) {
				index1 = i;
				break;
			}
		}

		if(index1 >= 0) {
			for(int j = len -1; j >= 0; j--) {
				if(nums[j] > nums[index1]) {
					index2 = j;
					break;
				}
			}
		}
		

		if(index1 == -1 && index2 == -1) {
			reverse(nums.begin(), nums.end());
		}
		else {
			int temp = nums[index1];
			nums[index1] = nums[index2];
			nums[index2] = temp;
			reverse(nums.begin() + index1 + 1, nums.end());
		}
	}

	/*
	Given a string, determine if a permutation of the string could form a palindrome.
	For example,
	"code" -> False, "aab" -> True, "carerac" -> True.
	*/
	bool canPermutePalindrome(string s) {
		vector<int> isEven(256, 0);
		int oddCount = 0;
		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			isEven[s[i]]++;
		}
		for (int i : isEven) {
			if (i / 2 * 2 != i) oddCount++;
		}
		return oddCount <= 1 ? true : false;
	}

	/*
	Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
	For example:
	Given s = "aabb", return ["abba", "baab"].
	Given s = "abc", return [].
	*/
	vector<string> generatePalindromes(string s) {
		vector<string> result;
		vector<int> isEven(256, 0);
		int oddCnt = 0;
		int oddIndex = 0;
		for (char c : s) {
			isEven[c]++;
		}
		for (int i = 0; i < static_cast<int>(isEven.size()); i++) {
			if (isEven[i] % 2 == 1) {
				oddCnt++;
				oddIndex = i;
			}
		}

		string middle;
		if (oddCnt > 1) {
			return result;
		}
		else if (oddCnt == 0) {
			middle = "";
		}
		else {
			middle = string(1, static_cast<char>(oddIndex));
		}

		string halfS;
		for (int i = 0; i < static_cast<int>(isEven.size()); i++) {
			if (isEven[i] > 0) {
				halfS += string(isEven[i] / 2, static_cast<char>(i));
			}
		}
		vector<string> halfPermute = generatePermute(halfS);
		for (string oneHalfPermute : halfPermute) {
			result.push_back(oneHalfPermute + middle + string(oneHalfPermute.rbegin(), oneHalfPermute.rend()));
		}
		return result;
	}

	/*
	The set [1,2,3,n] contains a total of n! unique permutations
	Given n and k, return the kth permutation sequence.
	Given n will be between 1 and 9 inclusive.
	*/
	string getPermutation(int n, int k){
		string s = "";
		for(int i = 1; i <= n; i++) {
			s = s + to_string(i);
		}
		k--;
		string result = "";
		while(s.size() >= 1) {
			int len = static_cast<int>(s.size());
			int modder = 1;
			for(int i = 1; i < len; i++) {
				modder = modder*i;
			}
			int curIndex = k/modder;
			k = k%modder;
			string selectedNum = string(1, s[curIndex]);
			result = result + selectedNum;
			s.erase(curIndex, 1);
		}
		return result;
	}


private:
	vector<string> generatePermute(string s) {
		vector<string> result;
		result.push_back("");

		for (int i = 0; i < static_cast<int>(s.size()); i++) {
			set<string> curSet;
			for (string onePerm : result) {
				for (int j = 0; j < static_cast<int>(onePerm.size()) + 1; j++) {
					onePerm.insert(j, 1, s[i]);
					curSet.insert(onePerm);
					onePerm.erase(j, 1);
				}
			}
			result = vector<string>(curSet.begin(), curSet.end());
		}
		return result;
	}
};

Permutation::Permutation()
{
}

Permutation::~Permutation()
{
}
