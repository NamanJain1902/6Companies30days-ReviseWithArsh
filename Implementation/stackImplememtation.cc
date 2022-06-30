#include<iostream>
#include<vector>
using namespace std;


template <typename T> 
class Array{
    vector<T> arr;
    
    public:
        Array() {}
        ~Array(){};
        
        void push(T val);
        void pop();
        T top();
};

template <typename T>
void Array<T>::push(T val) {
    this->arr.push_back(val);
}

template <typename T>
void Array<T>::pop(){
    this->arr.pop_back();
}
template <typename T>
T Array<T>::top(){
    return this->arr[this->arr.size()-1];
}

int main()
{
    Array<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.pop();
    cout << stack.top() << endl;


    return 0;
}

