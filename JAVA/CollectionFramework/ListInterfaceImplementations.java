import java.util.*;


public class ListInterfaceImplementations {

    public void ArrayListImplementation() {
        ArrayList<Integer> al = new ArrayList<Integer>();
        System.out.println("ArrayListImplementation");

        for(int i=1; i<10; ++i) {
            al.add(i);  
        }
        System.out.println(al);

        al.remove(3);
        System.out.println(al);
        

        for(int i=0; i<al.size(); ++i) {
            System.out.print(al.get(i) + " ");
        }
        System.out.println();
    }

    public void LinkedListImplementation() {
        LinkedList<Integer> ll = new LinkedList<Integer>();
        System.out.println("LinkedListImplementation");
        
        for(int i=1; i<=5; ++i) {
            ll.add(i);
        }
        System.out.println(ll);

        ll.remove(3);

        System.out.println(ll);

        for(int i=0; i < ll.size(); ++i){
            System.out.print(ll.get(i) + " ");
        }
        System.out.println();
    }

    public void VectorImplementation() {
        Vector<Integer> v = new Vector<Integer>();
        System.out.println("VectorImplementation");

        for(int i=1; i<=5; ++i) {
            v.add(i);
        }
        System.out.println(v);

        v.remove(3);

        System.out.println(v);

        for(int i=0; i < v.size(); ++i){
            System.out.print(v.get(i) + " ");
        }
        System.out.println();
    }

    public void StackImplementation() {
        /* 
         * Stack is a subclass of Vector and a legacy class. 
         * It is thread-safe which might be overhead in an environment 
         * where thread safety is not needed. An alternate to Stack is 
         * to use ArrayDequeue which is not thread-safe and has faster
         * array implementation.
        */
        Stack<String> stack = new Stack<String>();
        System.out.println("StackImplementation");

        stack.push("A");    
        stack.push("B");
        stack.push("C");
        stack.push("D");

        Iterator<String> itr = stack.iterator();

        while(itr.hasNext()) {
            System.out.println(itr.next() + " ");
        }
        System.out.println();

        stack.pop();

        itr = stack.iterator();

        while(itr.hasNext()){
            System.out.println(itr.next() + " ");   
        }
    }


    public static void main(String[] args) {
        ListInterfaceImplementations ob = new ListInterfaceImplementations();
        
        ob.ArrayListImplementation();
        ob.LinkedListImplementation();
        ob.VectorImplementation();
        ob.StackImplementation();
    }
}
