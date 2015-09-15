import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by Kuilin on 8/5/2015.
 */
public class MyStack {

    private Queue<Integer> q1 = new LinkedList<Integer>();
    private Queue<Integer> q2 = new LinkedList<Integer>();

    // Push element x onto stack.
    public void push(int x) {
        q1.offer(x);

    }

    // Removes the element on top of the stack.
    public void pop() {
        while(q1.size() > 1) q2.offer(q1.poll());
        q1.poll();

        Queue<Integer> temp = q2;
        q2 = q1;
        q1 = temp;
    }

    // Get the top element.
    public int top() {
        while(q1.size() > 1) q2.offer(q1.poll());
        int top = q1.peek();
        q2.offer(q1.poll());

        Queue<Integer> temp = q2;
        q2 = q1;
        q1 = temp;

        return top;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q1.isEmpty();
    }
}
