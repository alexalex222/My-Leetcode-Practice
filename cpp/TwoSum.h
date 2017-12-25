#include<map>
using namespace std;
class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
		if(myMap.find(number) != myMap.end()) myMap[number]++;
		else myMap.emplace(number, 1);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
		for(map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
			it->second--;
			if(myMap.find(value - it->first) != myMap.end() && myMap[value - it->first]>=1) {
				it->second++;
				return true;
			}
			else it->second++;
		}
		return false;
	}
private:
	map<int, int> myMap;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
