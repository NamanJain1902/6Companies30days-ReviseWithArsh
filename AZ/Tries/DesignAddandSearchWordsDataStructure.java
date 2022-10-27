class Node {
    private final int K = 26;
    private Node[] links;
    private boolean is_end;
    
    public Node() {
        links = new Node[K];
    }
    public Node get(char ch) {
        return links[ch - 'a'];
    }
    public void put(char ch, Node node) {
        links[ch - 'a'] = node;
    }
    public boolean containsKey(char ch) {
        return (links[ch - 'a'] != null);
    }
    public void setEnd() {
        is_end = true;
    }
    public boolean contains(int i) {
        return links[i] != null;
    }
    public Node gt(int i){
        return links[i];
    }
    public boolean isEnd() {
        return is_end;
    }
}
class WordDictionary extends Node {
    private Node root;
    
    public WordDictionary() {
        root = new Node();
    }
    
    public void addWord(String word) {
        Node node = root;
        for(int i=0; i<word.length(); ++i) {
            char ch = word.charAt(i);
            if(!node.containsKey(ch)) {
                node.put(ch, new Node());
            }
            node = node.get(ch);
        }
        node.setEnd();
    }
    
    private boolean match(char[] chs, int k, Node node) {
        if (k == chs.length) {
            return node.isEnd();
        }
        if (chs[k] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node.contains(i) && match(chs, k + 1, node.gt(i))) {
                    return true;
                }
            }
        } else {
            return node.containsKey(chs[k]) && match(chs, k + 1, node.get(chs[k]));
        }
        return false;
    }
    
    // private boolean search(char[] word, Node node) {
    //     for(int i=0; (word[i] && node != null); ++i) {
    //         char ch = word[i];
    //         if(node.containsKey(ch)) {
    //             node = node.get(ch);
    //         } else if(ch == '.') {
    //             Node temp = node;
    //             for(int id=0; id<26; ++id) {
    //                 node = node.gt(id);
    //                 if(search(word.charAt(i+1), node)) {
    //                     return true;
    //                 }
    //             }
    //         } 
    //     }
    //     return node && node.isEnd();
    // }
    
    public boolean search(String word) {
        // return search(word.toCharArray(), root);
        return match(word.toCharArray(), 0, root);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
public class DesignAddandSearchWordsDataStructure extends WordDictionary{
    public static void main(String args[]) {
        WordDictionary trie = new WordDictionary();

        String[] ops   = {"Trie", "insert", "search", "search", "search", "insert", "search"};
        String[] words = {"", "apple", "apple", "app", "app", "app", "a.p"};
        
        for(int i=0; i<words.length; ++i){
            String op = ops[i];
            if(op == "insert") {
                trie.addWord(words[i]); 
            } else if(op == "search") {
                System.out.println(trie.search(words[i]));
            }
        }
    }
}
