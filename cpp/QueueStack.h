#include <iostream>
#include <stack>


using std::stack;



#ifndef QUEUESTACK
#define QUEUESTACK

class QueueS {

private:
	stack<int> s1;
	stack<int> s2;

public:
	// Push element x to the back of queue.
	void push(int x) {
		if (s1.empty()) s1.push(x);
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(x);
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}

	}

	// Removes the element from in front of queue.
	void pop(void) {
		s1.pop();
	}

	// Get the front element.
	int peek(void) {
		return s1.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s1.empty();
	}
};

#endif 
