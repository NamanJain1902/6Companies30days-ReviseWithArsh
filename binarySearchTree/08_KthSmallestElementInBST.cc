#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* construct(vector<int>& arr) {
    Node* root = new Node(arr[0]);
    pair<Node*, int> p = {root, 1};

    stack<pair<Node*, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty()) {

        if (st.top().second == 1) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->left = new Node(arr[idx]);
                pair<Node*, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->right = new Node(arr[idx]);
                pair<Node*, int> rp = {st.top().first->right, 1};
                st.push(rp);
            } else {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else {
            st.pop();
        }

    }
    return root;
}


int min(Node *node){
    //     Write your code here
    return !node->left ? node->data: min(node->left);
}

int max(Node *node){
    //     Write your code here
    return !node->right ? node->data : max(node->right);
}

int sum(Node * node){

    //     Write your code here
    return !node ? 0 : (sum(node->left) + sum(node->right) + node->data);
}


int size(Node * node){

    //     Write your code here
    return !node ? 0 : (size(node->left) + size(node->right) + 1);
}


bool find(Node * node, int data){
    // Alternate 1
      return !node ? false
               : node->data == data ? true
                                    : (
                                  node->data < data ? find(node->right, data) 
                                                    : find(node->left, data)
               );
    // Alternate 2
    if(!node) return false;
    if(node->data == data) return true;
    if(node->data > data) return find(node->left, data);
    else if(node->data < data) return find(node->right, data);
    return false;
}
class Solution{
public:

    //  Sol 1, Time: O(N) and Space: O(N + N) due to vector and recursion stack
    void inorder(Node *root, vector<int> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    //  Sol 1
    int kthSmallest1(Node* root, int k) {
        vector<int> v;
        inorder(root, v);
        return v[k-1];
    }

    // O(N) faster since it's not using recursive calls
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        
        while(true) {
            while(root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }

    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (x == "n") {
            arr[i] = -1;

        }
        else {
            arr[i] = stoi(x);
        }
    }
    int data;
    cin >> data;
    Node* root = construct(arr);
    cout << size(root) << "\n" << sum (root) << "\n" << max(root) << "\n" << min(root) <<  "\n";
    if (find(root, data)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
