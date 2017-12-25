#pragma once
class NumArrayImu {
public:
	NumArrayImu(vector<int> &nums) {
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

class NumArrayMu {
private:
	vector<int> accum;
public:
	NumArrayMu(vector<int> &nums) {
		accum.push_back(0);
		for (int num : nums) {
			accum.push_back(accum.back() + num);
		}
	}

	void update(int i, int val) {
		int oldVal = accum[i + 1] - accum[i];
		int diff = val - oldVal;
		for (int j = i + 1; j < static_cast<int>(accum.size()); j++) {
			accum[j] = accum[j] + diff;
		}
	}

	int sumRange(int i, int j) {
		return accum[j + 1] - accum[i];
	}
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);