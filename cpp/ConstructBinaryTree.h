#pragma once
class ConstructBinaryTree {
public:
	TreeNode* buildTreePrePost(vector<int>& preorder, vector<int>& inorder) {
		int preStart = 0;
		int preEnd = static_cast<int>(preorder.size()) - 1;
		int inStart = 0;
		int inEnd = static_cast<int>(inorder.size()) - 1;

		return constructPrePost(preorder, preStart, preEnd, inorder, inStart, inEnd);
	}

	TreeNode* constructPrePost(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
		if (preStart > preEnd || inStart > inEnd) return NULL;

		int rootVal = preorder[preStart];
		TreeNode* root = new TreeNode(rootVal);

		int k = 0;
		for (int i = inStart; i <= inEnd; i++) {
			if (inorder[i] == rootVal) {
				k = i;
				break;
			}
		}

		root->left = constructPrePost(preorder, preStart + 1, preStart + (k - inStart), inorder, inStart, k - 1);
		root->right = constructPrePost(preorder, preStart + (k - inStart) + 1, preEnd, inorder, k + 1, inEnd);

		return root;
	}

	TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder) {
		int inStart = 0;
		int inEnd = static_cast<int>(inorder.size()) - 1;
		int postStart = 0;
		int postEnd = static_cast<int>(postorder.size()) - 1;
		return constructInPost(inorder, inStart, inEnd, postorder, postStart, postEnd);
	}

	TreeNode* constructInPost(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
		if (inStart > inEnd || postStart > postEnd) return NULL;

		int rootVal = postorder[postEnd];
		TreeNode* root = new TreeNode(rootVal);

		int k = 0;
		for (int i = inStart; i <= inEnd; i++) {
			if (inorder[i] == rootVal) {
				k = i;
				break;
			}
		}

		root->left = constructInPost(inorder, inStart, k - 1, postorder, postStart, postStart + (k - inStart - 1));
		root->right = constructInPost(inorder, k + 1, inEnd, postorder, postStart + (k - inStart), postEnd - 1);

		return root;
	}

	bool isValidSerialization(string preorder) {
		vector<string> myStack;
		istringstream ss(preorder);
		string element;
		while (getline(ss, element, ',')) {
			myStack.push_back(element);

			while (myStack.size() >= 3 && myStack[myStack.size() - 1] == "#" && myStack[myStack.size() - 2] == "#" && myStack[myStack.size() - 3] != "#") {
				myStack.pop_back();
				myStack.pop_back();
				myStack.pop_back();
				myStack.push_back("#");
			}
		}
		return (myStack.size() == 1 && myStack[0] == "#");
	}

	/*
	Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
	You may assume each number in the sequence is unique.
	*/
	bool verifyPreorder(vector<int>& preorder) {
		int low = INT_MIN;
		stack<int> treeStack;
		for (int val : preorder) {
			if (val < low) return false;
			while (!treeStack.empty() && val > treeStack.top()) {
				low = treeStack.top();
				treeStack.pop();		
			}
			treeStack.push(val);
		}
		return true;
	}
};
