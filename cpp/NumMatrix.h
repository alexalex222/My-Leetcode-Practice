#pragma once
class NumMatrix {
private:
	vector<vector<int>> myMatrix;
	vector<vector<int>> sumMatrix;
public:
	NumMatrix(vector<vector<int>> &matrix) {
		myMatrix = matrix;
		for (vector<int> nums : matrix) {
			vector<int> accum;
			accum.push_back(0);
			for (int num : nums) {
				accum.push_back(accum.back() + num);
			}
			sumMatrix.push_back(accum);
		}
	}

	void update(int row, int col, int val) {
		for (int i = col + 1; i < static_cast<int>(sumMatrix[0].size()); i++) {
			sumMatrix[row][i] = sumMatrix[row][i] + val - myMatrix[row][col];
		}
		myMatrix[row][col] = val;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int r = row1; r <= row2; r++) {
			sum = sum + sumMatrix[r][col2 + 1] - sumMatrix[r][col1];
		}
		return sum;
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
