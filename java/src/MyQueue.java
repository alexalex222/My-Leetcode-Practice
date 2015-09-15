import java.util.Stack;

/**
 * Created by Kuilin on 8/8/2015.
 */
public class MyQueue {

    private Stack<Integer> s1 = new Stack<Integer>();
    private Stack<Integer> s2 = new Stack<Integer>();

    // Push element x to the back of queue.
    public void push(int x) {
        if(s1.isEmpty()) {
            s1.push(x);
        } else {
            while(!s1.isEmpty()) s2.push(s1.pop());
            s1.push(x);
            while(!s2.isEmpty()) s1.push(s2.pop());
        }

    }

    // Removes the element from in front of queue.
    public void pop() {
        s1.pop();
    }

    // Get the front element.
    public int peek() {
        return s1.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return s1.isEmpty();

    }
}
