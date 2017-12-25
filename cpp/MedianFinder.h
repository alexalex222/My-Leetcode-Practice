class MedianFinder {
private:
	priority_queue<int> lowerHalfHeap;
	priority_queue<int, vector<int>, std::greater<int>> higherHalfHeap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
		lowerHalfHeap.push(num);
		higherHalfHeap.push(lowerHalfHeap.top());
		lowerHalfHeap.pop();

		if(lowerHalfHeap.size() < higherHalfHeap.size()) {
			lowerHalfHeap.push(higherHalfHeap.top());
			higherHalfHeap.pop();
		}
    }

    // Returns the median of current data stream
    double findMedian() {
		if(lowerHalfHeap.size() == higherHalfHeap.size()) {
			return static_cast<double>(lowerHalfHeap.top() + higherHalfHeap.top())/2;
		}
		else {
			return static_cast<double>(lowerHalfHeap.top());
		}
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
