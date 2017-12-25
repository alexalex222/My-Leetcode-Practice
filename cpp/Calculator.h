#pragma once
class Calculator {
public:
	/*
	Implement a basic calculator to evaluate a simple expression string.
	The expression string may contain open ( and closing parentheses ), 
	the plus + or minus sign -, non-negative integers and empty spaces
	*/
	int calculate(string s) {
		int result = 0;
		stack<int> myStack;
		myStack.push(1);
		int sign = 1;
		int i = 0;
		int len = static_cast<int>(s.size());
		while (i < len) {
			char c = s[i];
			if (c == ' ') {
				i++;
			}
			else if (c == '+') {
				sign = 1;
				i++;
			}
			else if (c == '-') {
				sign = -1;
				i++;
			}
			else if (c == '(') {
				myStack.push(sign*myStack.top());
				sign = 1;
				i++;
			}
			else if (c == ')') {
				myStack.pop();
				i++;
			}
			else  {
				int num = 0;
				while (i < len && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					i++;
				}
				result += num*sign*myStack.top();
			}
		}
		return result;
	}


	/*
	Implement a basic calculator to evaluate a simple expression string.
	The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
	The integer division should truncate toward zero.
	*/
	int calculateII(string s) {
		int num = 0;
		stack<int> myStack;
		char oper = '+';
		int i = 0;
		int len = static_cast<int>(s.size());
		int result = 0;
		while (i < len) {
			while (s[i] == ' ') {
				i++;
			}
			if (s[i] >= '0' && s[i] <= '9') {
				num = 0;
				while (i < len && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					i++;
				}
			}

			if (s[i] == '+' || s[i] == '-'  || s[i] == '*' || s[i] == '/' || i >= len - 1) {
				if (oper == '+') {
					myStack.push(num);
				}
				if (oper == '-') {
					myStack.push(-num);
				}
				if (oper == '*') {
					int temp = myStack.top();
					myStack.pop();
					myStack.push(temp*num);
				}
				if (oper == '/') {
					int temp = myStack.top();
					myStack.pop();
					myStack.push(temp / num);
				}
				oper = s[i];
				i++;
			}
		}
		while (!myStack.empty()) {
			result = result + myStack.top();
			myStack.pop();
		}
		return result;
	}
};