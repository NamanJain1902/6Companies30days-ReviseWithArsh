#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
public:
    class Node
    {
        public:
            int key;
            int val;
            Node *prev;
            Node *next;
            Node(int _key, int _val)
            {
                key = _key;
                val = _val;
            }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void add_node(Node *new_node)
    {
        Node *temp = this->head->next;
        new_node->next = temp;
        new_node->prev = this->head;
        this->head->next = new_node;
        temp->prev = new_node;
    }

    void delete_node(Node *del_node)
    {
        Node *delPrev = del_node->prev;
        Node *delNext = del_node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        // delete del_node;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            Node *res_node = m[key_];
            int res = res_node->val;
            m.erase(key_);
            delete_node(res_node);
            add_node(res_node);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            Node *existing_node = m[key_];
            // m.erase(key_);
            delete_node(existing_node);
        }
        else if (m.size() == this->capacity)
        {
            m.erase(this->tail->prev->key);
            delete_node(this->tail->prev);
        }
        add_node(new Node(key_, value));
        m[key_] = this->head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    
}