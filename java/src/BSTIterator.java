import java.util.Stack;

/**
 * Created by Kuilin on 8/27/2015.
 */
public class BSTIterator {

    Stack<TreeNode> myStack;

    public BSTIterator(TreeNode root) {
        myStack = new Stack<TreeNode>();
        while(root != null) {
            myStack.push(root);
            root = root.left;
        }

    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !myStack.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode node = myStack.pop();
        int result = node.val;
        if(node.right != null) {
            node = node.right;
            while(node != null) {
                myStack.push(node);
                node = node.left;
            }
        }
        return result;
    }
}

