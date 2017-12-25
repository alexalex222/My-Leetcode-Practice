#pragma once

#include<vector>

using std::vector;

#ifndef RANGESUM
#define RANGESUM

class NumArray {
public:
	NumArray(vector<int> &nums) {
		this->accum.push_back(0);
		for (int num : nums) {
			this->accum.push_back(this->accum.back() + num);
		}
	}

	int sumRange(int i, int j) {
		return this->accum[j + 1] - this->accum[i];
	}

private:
	vector<int> accum;
};

#endif