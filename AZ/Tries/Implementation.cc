#include<iostream>
using namespace std;


class Node {
    private:
        const static short K = 26;
        char ch;
        Node *links[K] = {NULL};
        bool is_end;

    public:
        Node() {
            is_end = false;
        }
        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;    
        }
        bool isEnd() {
            return is_end;
        }
        void put(char ch, Node *node) {
            links[ch - 'a'] = node;
        }
        void setEnd() {
            is_end = true;
        }
        char getChar() {
            return ch;
        }
        Node *get(char ch) {
            return links[ch - 'a'];
        }
};

class Trie {
    Node *root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;        
        for(auto ch: word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;

        for(char ch: word) {
            if(node->containsKey(ch)) {
                node = node->get(ch);
            } else break;
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node *node = root;
        for(char ch: prefix) {
            if(node->containsKey(ch)) {
                node = node->get(ch);
            } else return false;
        }
        return true;
    }
};

int main() {
    Trie *trie;
    string ops[] = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    string words[] = {"", "apple", "apple", "app", "app", "app", "app"};
    
    int n = sizeof(words) / sizeof(words[0]);
    cout << boolalpha;
    for(int i=0; i<n; ++i){
        string op = ops[i];
        if(op == "insert") {
            trie->insert(words[i]); 
        } else if(op == "search") {
            cout << trie->search(words[i]) << endl;
        } else if(op == "startsWith") {
            cout << trie->startsWith(words[i]) << endl;
        } else {
            trie = new Trie();
        }
    }
    return 0;
}