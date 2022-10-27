
import java.util.PriorityQueue;

public class QueueInterfaceImplementation {
    public static void PriorityQueueImplementation() {
        System.out.println("PriorityQueueImplementation");

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        // default is min-heap

        pq.add(1);
        pq.add(2);
        pq.add(3);

        System.out.println(pq.peek());
        
        System.out.println(pq.poll());

        System.out.println(pq.peek());
    }

    public static void main(String[] args) {
        PriorityQueueImplementation();
    }
}
