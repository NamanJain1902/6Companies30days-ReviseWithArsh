#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data=0;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(int data)
        {
            this->data = data;
        }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

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

//Display function
void display(Node *node)
{
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
vector<int> balanced(Node *node){
    if(!node) return {1, 0};
    vector<int> islth = balanced(node->left);
    vector<int> isrth = balanced(node->right);

    vector<int> isnth(2, 0);

    isnth[0] = islth[0] && isrth[0] && (abs(islth[1] - isrth[1]) <= 1);
    isnth[1] = max(islth[1], isrth[1]) + 1;
    return isnth;
}
int isbalance(Node *node)
{
    // write your code here
    return balanced(node)[0];
}



bool isbal = true;

int isbalance_pep(Node *node)
{
    if(node == nullptr)
    {
        return -1;
    }

    int l = isbalance(node->left);
    int r = isbalance(node->right);

    int gap = abs(l-r);
    if(gap>1)
    {
        isbal = false;
    }
    int th = max(l,r)+1;

    return th;

}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n,0);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
        if (tmp=="n") {
            arr[i] = -1;
        } else {
            arr[i] = stoi(tmp);
        }
    }


    Node *root = constructTree(arr);

    int r = isbalance(root);
    if(r == 1)
        cout << "true";
    else
        cout<<"false";
}
