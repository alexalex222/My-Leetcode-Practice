#pragma once
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
	NestedInteger();

	// Constructor initializes a single integer.
	NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;

	/*
	Given a nested list of integers represented as a string, implement a parser to deserialize it.
	Each element is either an integer, or a list -- whose elements may also be integers or other lists.
	*/
	NestedInteger deserialize(string s) {
		NestedInteger result;
		int len = static_cast<int>(s.size());
		if (len < 1) return result;
		stack<NestedInteger> numStack;
		int sign = 1;
		int i = 0;
		while (i < len) {
			if (s[i] >= '0' && s[i] <= '9') {
				int num = 0;
				while (s[i] >= '0' && s[i] <= '9' && i < len) {
					num = num * 10 + s[i] - '0';
					i++;
				}
				num = sign*num;
				sign = 1;
				if (!numStack.empty()) {
					numStack.top().add(NestedInteger(num));
				}
				else {
					NestedInteger nI = NestedInteger(num);
					numStack.push(nI);
				}
			}
			else if (s[i] == '[') {
				numStack.push(NestedInteger());
				i++;
			}
			else if (s[i] == ']') {
				NestedInteger nI = numStack.top();
				numStack.pop();
				if (numStack.empty()) numStack.push(nI);
				else numStack.top().add(nI);
				i++;
			}
			else if (s[i] == '-') {
				sign = -1;
				i++;
			}
			else {
				i++;
			}
		}
		if(!numStack.empty()) return numStack.top();
		else return result;
	}


	/*
	Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
	Each element is either an integer, or a list -- whose elements may also be integers or other lists.
	*/
	int depthSum(vector<NestedInteger>& nestedList) {
		int result = 0;
		for (NestedInteger inner : nestedList) {
			result += depthSum(inner, 1);
		}
		return result;
	}

	int depthSum(NestedInteger ni, int depth) {
		int result = 0;
		if (ni.isInteger()) return depth*ni.getInteger();
		for (NestedInteger inner : ni.getList()) {
			result += depthSum(inner, depth + 1);
		}
		return result;
	}

	/*
	Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
	Each element is either an integer, or a list -- whose elements may also be integers or other lists.
	the weight is defined from bottom up. i.e., the leaf level integers have weight 1, 
	and the root level integers have the largest weight.
	*/
	int depthSumInverse(vector<NestedInteger>& nestedList) {
		int res = 0;
		vector<vector<int>> v;
		for (auto a : nestedList) {
			helper(a, 0, v);
		}
		for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i) {
			for (int j = 0; j < static_cast<int>(v[i].size()); ++j) {
				res += v[i][j] * (static_cast<int>(v.size()) - i);
			}
		}
		return res;
	}

	void helper(NestedInteger &ni, int depth, vector<vector<int>> &v) {
		vector<int> t;
		if (depth < static_cast<int>(v.size())) t = v[depth];
		else v.push_back(t);
		if (ni.isInteger()) {
			t.push_back(ni.getInteger());
			if (depth < static_cast<int>(v.size())) v[depth] = t;
			else v.push_back(t);
		}
		else {
			for (auto a : ni.getList()) {
				helper(a, depth + 1, v);
			}
		}
	}
};

class NestedIterator {
private:
	stack<NestedInteger> nestStack;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		while (!nestedList.empty()) {
			nestStack.push(nestedList.back());
			nestedList.pop_back();
		}
	}

	int next() {
		int result = nestStack.top().getInteger();
		nestStack.pop();
		return result;
	}

	bool hasNext() {
		while (!nestStack.empty() && !nestStack.top().isInteger()) {
			vector<NestedInteger> vN = nestStack.top().getList();
			nestStack.pop();
			while (!vN.empty()) {
				nestStack.push(vN.back());
				vN.pop_back();
			}
		}
		return !nestStack.empty();
	}
};

/**
* Your NestedIterator object will be instantiated and called as such:
* NestedIterator i(nestedList);
* while (i.hasNext()) cout << i.next();
*/
