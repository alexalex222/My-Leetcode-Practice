#include<list>
#include<map>
using namespace std;

struct cacheNode {
	int key;
	int val;
	cacheNode(int k, int v) {
		key = k;
		val = v;
	}
};

/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.
*/
class LRUCache{
private:
	unordered_map<int, list<cacheNode>::iterator> myMap;
	list<cacheNode> cacheList;
	int capacity;
public:
    LRUCache(int capacity) {
		this->capacity = capacity;
    }
    
	//Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    int get(int key) {
		if(myMap.find(key) != myMap.end()) {
			cacheList.splice(cacheList.begin(), cacheList, myMap[key]);
			myMap[key] = cacheList.begin();
			return myMap[key]->val;
		}
		else {
			return -1;
		}
    }
    
	//Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the 
    void set(int key, int value) {
		if(myMap.find(key) == myMap.end()) {
			if(static_cast<int>(myMap.size()) == capacity) {
				myMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(cacheNode(key, value));
			myMap.emplace(key, cacheList.begin());
		}
		else {
			cacheList.splice(cacheList.begin(), cacheList, myMap[key]);
			myMap[key] = cacheList.begin();
			myMap[key]->val = value;
		}
    }
};

//Design and implement a data structure for Least Frequently Used (LFU) cache.
class LFUCache {
private:
	int capacity;
	multimap<size_t, cacheNode> freqKey;
	unordered_map<int, multimap<size_t, cacheNode>::iterator> keyPos;
public:
    LFUCache(int capacity) {
		this->capacity = capacity;
    }
    //Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    int get(int key) {
		if(capacity > 0 && keyPos.find(key) != keyPos.end()) {
			multimap<size_t, cacheNode>::iterator it = keyPos[key];
			pair<size_t, cacheNode> updatedElement = make_pair(it->first + 1, it->second);
			int result = it->second.val;
			freqKey.erase(it);
			keyPos[key] = freqKey.emplace(updatedElement);
			return result;
		}
		else return -1;
    }
    
	/*
	Set or insert the value if the key is not already present. When the cache reaches its capacity, 
	it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, 
	when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
	*/
    void set(int key, int value) {
		if (keyPos.find(key) == keyPos.end()) {
			if (static_cast<int>(keyPos.size()) == capacity && capacity > 0) {
				keyPos.erase(freqKey.begin()->second.key);
				freqKey.erase(freqKey.begin());
			}
			if(capacity > 0) keyPos[key] = freqKey.emplace(1, cacheNode(key, value));		
		}
		else {
			multimap<size_t, cacheNode>::iterator it = keyPos[key];
			pair<size_t, cacheNode> updatedElment = make_pair(it->first + 1, cacheNode(key, value));
			freqKey.erase(it);
			keyPos[key] = freqKey.insert(updatedElment);
		}
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
