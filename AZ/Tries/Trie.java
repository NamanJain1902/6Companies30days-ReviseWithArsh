import java.util.*;

class Node{
    private final int K = 26;
    private char ch;
    private Node[] links;
    private boolean is_end;     

    public Node() {
        links = new Node[K];
        is_end = false;
    }

    public boolean containsKey(char ch) {
        return links[ch - 'a'] != null;    
    }
    public boolean isEnd() {
        return is_end;
    }
    public void put(char ch, Node node) {
        links[ch - 'a'] = node;
    }
    public void setEnd() {
        is_end = true;
    }
    public char getChar() {
        return ch;
    }
    public Node get(char ch) {
        return links[ch - 'a'];
    }
}

class Trie {

    private Node root;

    public Trie(){
        root = new Node();
    }

    public void insert(String word) {
        Node node = root;        
        for(int i=0; i< word.length(); ++i) {
            char ch = word.charAt(i);
            if(!node.containsKey(ch)) {
                node.put(ch, new Node());
            }
            node = node.get(ch);
        }
        node.setEnd();
    }

    public boolean search(String word) {
        Node node = root;

        for(int i=0; i< word.length(); ++i) {
            char ch = word.charAt(i);
            if(node.containsKey(ch)) {
                node = node.get(ch);
            } else break;
        }

        return node.isEnd();
    }

    boolean startsWith(String prefix) {
        Node node = root;
        for(int i=0; i<prefix.length(); ++i) {
            char ch = prefix.charAt(i);
            if(node.containsKey(ch)) {
                node = node.get(ch);
            } else return false;
        }
        return true;
    }
    
    public static void main(String args[]) {
        
        Trie trie = new Trie();
        String ops[] = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
        String words[] = {"", "apple", "apple", "app", "app", "app", "app"};
        
        for(int i=0; i<words.length; ++i){
            String op = ops[i];
            if(op == "insert") {
                trie.insert(words[i]); 
            } else if(op == "search") {
                System.out.println(trie.search(words[i]));
            } else if(op == "startsWith") {
                System.out.println(trie.startsWith(words[i]));
            } else {
                continue;
                // trie = new Trie();
            }
        }
    }

    public static void input() {

        Scanner sc = new Scanner(System.in);

        try{
            int i = sc.nextInt();
            String s = sc.next();
            System.out.println("My first input in java: " + i + " named " + s);
        } finally{
            sc.close();
        }
    }
}
