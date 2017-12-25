class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
		if(myMap.find(message) == myMap.end()) {
			myMap.emplace(message, timestamp);
			return true;
		}
		else if(timestamp - myMap[message] >= 10) {
			myMap[message] = timestamp;
			return true;
		}
		return false;
    }
private:
	map<string, int> myMap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
