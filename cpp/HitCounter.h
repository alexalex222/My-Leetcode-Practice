#include<unordered_map>
using namespace std;
class HitCounter {
private:
	unordered_map<int, int> hitMap;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
		if(hitMap.find(timestamp) == hitMap.end()) hitMap.emplace(timestamp, 1);
		else hitMap[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int totalHits = 0;
		unordered_map<int, int>::iterator it = hitMap.begin();
		while( it != hitMap.end()) {
			if(timestamp - it->first < 300) {
				totalHits = totalHits + it->second;
				it++;
			}
			else {
				hitMap.erase(it++);
			}
		}
		return totalHits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
