import java.util.Stack;

/**
 * Created by Kuilin on 9/9/2015.
 */
public class MinStack {
    private Stack<Integer> myStack;
    private Stack<Integer> minStack;


    public MinStack() {
        myStack = new Stack<Integer>();
        minStack = new Stack<Integer>();
    }

    // Push element x onto stack.
    public void push(int x) {
        myStack.push(x);
        if(minStack.isEmpty() || x <= minStack.peek()) {
            minStack.push(x);
        }
    }

    // Removes the element on top of the stack.
    public void pop() {
        if(myStack.isEmpty()) return;

        if(myStack.peek().equals(minStack.peek())) {
            minStack.pop();
        }

        myStack.pop();

    }

    // Get the top element.
    public int top() {
        return  myStack.peek();
    }

    // Retrieve the minimum element in the stack.
    public int getMin() {
        return minStack.peek();
    }


    public static void main(String[] args) {
        MinStack testStack = new MinStack();
        testStack.push(2);
        testStack.push(0);
        testStack.push(3);
        testStack.push(0);
        int temp1 = testStack.getMin();
        testStack.pop();
        int temp2 = testStack.getMin();
        testStack.pop();;
        int temp3 = testStack.getMin();
        testStack.pop();;
        int temp4 = testStack.getMin();
        testStack.pop();


        System.out.println(temp1);
        System.out.println(temp2);
    }

}

