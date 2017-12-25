#pragma once
#include<vector>
#include<map>
using namespace std;
class RandomizedSet {
private:
	vector<int> nums;
	unordered_map<int, int> myMap;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (myMap.find(val) != myMap.end()) {
			return false;
		}	
		nums.push_back(val);
		myMap[val] = static_cast<int>(nums.size()) - 1;
		return true;	
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (myMap.find(val) == myMap.end()) {
			return false;
		}
		int last = nums.back();
		myMap[last] = myMap[val];
		nums[myMap[last]] = last;
		nums.pop_back();
		myMap.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

/*
Design a data structure that supports all following operations in average O(1) time.
Note: Duplicate elements are allowed.
*/
class RandomizedCollection {
private:
	vector<int> nums;
	unordered_map<int, vector<int>> myMap;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		if (myMap.find(val) == myMap.end()) {
			nums.push_back(val);
			vector<int> location = vector<int>(1, static_cast<int>(nums.size()) - 1);
			myMap[val] = location;
			return true;
		}
		else {
			nums.push_back(val);
			myMap[val].push_back(static_cast<int>(nums.size()) - 1);
			return false;
		}
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (myMap.find(val) == myMap.end()) {
			return false;
		}
		int last = nums.back();
		myMap[last].back() = myMap[val].back();
		nums[myMap[val].back()] = last;
		nums.pop_back();
		myMap[val].pop_back();
		if (myMap[val].size() == 0) {
			myMap.erase(val);
		}
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};