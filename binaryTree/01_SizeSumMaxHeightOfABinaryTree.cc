#include<iostream>
#include<climits>
#include<string.h>
#include<vector>

using namespace std;

// structure of node
class Node
{
    public:
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(int data)
        {
            this->data = data;
        }
};

class Pair {
    public:
        Node * node = nullptr;
        int state=0;

        Pair(Node *node, int state) {
            this->node = node;
            this->state = state;
        }
};

int idx = 0;
Node *constructTree(vector<int> &arr) {
    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node) {
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

int size(Node *node) {
    if(node->left == node->right && node->left == NULL) return 1;
    int lsize = 0, rsize = 0;

    if(node->left != NULL)
        lsize = size(node->left);
    if(node->right != NULL)
        rsize = size(node->right);

    return lsize + rsize + 1;
}

int height(Node *node) {
    if(node->left == node->right && node->left == NULL) return 0;
    int lsize = -1, rsize = -1;

    if(node->left != NULL)
        lsize = height(node->left);

    if(node->right != NULL)
        rsize = height(node->right);

    return max(lsize, rsize) + 1;
}

int maximum(Node *node) {
    if(node->left == node->right && node->left == NULL) return node->data;

    int lmax = INT_MIN, rmax = INT_MIN;
    if(node->left)
        lmax = maximum(node->left);

    if(node->right)
        rmax = maximum(node->right);

    return max(lmax, max(rmax, node->data));
}

int sum(Node *node) {
    if(node->left == node->right && node->left == NULL) 
        return node->data;

    int lsum = 0, rsum = 0;
    if(node->left != NULL)
        lsum = sum(node->left);

    if(node->right != NULL)
        rsum = sum(node->right);

    return lsum + rsum + node->data;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;

        if(temp=="n")
        {
            arr[i] = -1;  
        }
        else
        {
            arr[i] = stoi(temp); 
        }
    }

    Node *root = constructTree(arr);

    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout<<sz<<endl;
    cout<<sm<<endl;
    cout<<max<<endl;
    cout<<ht<<endl;
}

