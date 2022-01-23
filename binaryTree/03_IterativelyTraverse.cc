#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int data){
        this->data = data;
        left = right = NULL;
    }
};


void inorder(Node *root){
    stack<Node*> st;
    Node *curr = root;

    while(curr != NULL || !st.empty()){
        /* reach the left most node of the curr node*/
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr = st.top();
        st.pop();
        

        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main(){
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    puts("");
}
