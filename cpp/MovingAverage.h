#include<queue>

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
		this->size = size;
        sum = 0;
    }
    
    double next(int val) {
		if(static_cast<int>(myQueue.size()) > size){
			sum = sum - myQueue.front();
			myQueue.pop();
		}
		myQueue.push(val);
		sum = sum + val;
		return sum/(static_cast<int>(myQueue.size()));
    }
private:
	int size;
	std::queue<int> myQueue;
	double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
