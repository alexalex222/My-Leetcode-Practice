class BSTIterator {
private:
	stack<TreeNode*> treeStack;
public:
    BSTIterator(TreeNode *root) {
        while(root) {
			treeStack.push(root);
			root = root->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !treeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
		TreeNode* tempNode = treeStack.top();
		int result = tempNode->val;
		treeStack.pop();
		if(tempNode->right) {
			tempNode = tempNode->right;
			while(tempNode) {
				treeStack.push(tempNode);
				tempNode = tempNode->left;
			}
		}
		return result;
    }
};
