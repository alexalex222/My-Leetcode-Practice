#pragma once

#include<stack>

using std::stack;

class MinStack {
public:
	void push(int x) {
		myStack.push(x);
		if (minStack.empty() || x <= minStack.top()) minStack.push(x);
	}

	void pop() {
		if (myStack.top() == minStack.top()) minStack.pop();
		myStack.pop();
	}

	int top() {
		return myStack.top();
	}

	int getMin() {
		return minStack.top();
	}

private:
	stack<int> myStack;
	stack<int> minStack;
	int min;
};