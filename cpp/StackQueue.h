#include <iostream>
#include <queue>


using std::queue;



#ifndef STACKQUEUE
#define STACKQUEUE

class StackQ {
private:
	queue<int> q1 = queue<int>();
	queue<int> q2 = queue<int>();

public:
	// Push element x onto stack.
	void push(int x) {
		q1.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		
		queue<int> temp = q2;
		q2 = q1;
		q1 = temp;
	}

	// Get the top element.
	int top() {
		return q1.back();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty();
	}
};

#endif


