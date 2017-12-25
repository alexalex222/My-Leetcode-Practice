#include<vector>
using namespace std;
class PhoneDirectory {
private:
	vector<bool> availableFlag;
	vector<int> recycle;
	int max_num;
	int nextPhoneNumber;
	int idx;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
		this->max_num = maxNumbers;
		this->nextPhoneNumber = 0;
		this->idx = 0;
		this->availableFlag.resize(maxNumbers, true);
		this->recycle.resize(maxNumbers);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
		if(this->nextPhoneNumber == this->max_num && idx <= 0) return -1;
		if(idx > 0) {
			int t = recycle[--idx];
			availableFlag[t] = false;
			return t;
		}
		availableFlag[nextPhoneNumber] = false;
		return this->nextPhoneNumber++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
		return number >= 0 && number < this->max_num && availableFlag[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
		if(number >= 0 && number < this->max_num && !availableFlag[number]) {
			recycle[idx] = number;
			idx++;
			availableFlag[number] = true;
		}
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
