#include<iostream>
#include<vector>
using namespace std;


template <typename T> 
class queue{
    struct Node {
        T Node;
        Node *prev, *next;
    }
    
    public:
        queue() {}
        ~queue(){};
        
        void push(Node val);
        void pop();
        T font();
};

template <typename T>
void queue<T>::push(T val) {
    this->arr.push_back(val);
}

template <typename T>
void queue<T>::pop(){
    this->arr.pop_back();
}

template <typename T>
T queue<T>::front(){
    return this->arr[this->arr.size()-1];
}

int main()
{
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.pop();
    cout << q.front() << endl;

    return 0;
}

