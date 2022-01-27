#include <iostream>
#include <vector>

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

class Pair {
    public:
        Node *node=nullptr;
        int state=0;

        Pair(Node *node, int state) {
            this->node = node;
            this->state = state;
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


//Height function
int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

static int til = 0;
int tilt(Node *node) {
    if(!node) return 0;
    if(node->left == NULL and node->right == NULL) return node->data;
    // node->left->data  
    int ls = tilt(node->left);
    // node->right->data 
    int rs = tilt(node->right);

    // if(node->left and node->right)
    // node->data 
    int t = abs(ls - rs);

    til += t;
    int tot =  ls + rs + node->data;
    return tot;
    // return node->left->data + node->right->data + node->data; 
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


    Node * root = constructTree(arr);
    int r = tilt(root);
    cout<<til;
}
