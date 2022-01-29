#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};


Node* construct(vector<int> & arr){
    Node* root=new Node(arr[0]);
    pair<Node*,int> p={root,1};

    stack<pair<Node*,int>> st;
    st.push(p);

    int idx=1;
    while(!st.empty()){
       
        if(st.top().second==1){
            st.top().second++;
            if(arr[idx]!=-1){
                st.top().first->left=new Node(arr[idx]);
                pair<Node*,int> lp={st.top().first->left,1};
                st.push(lp);
            }
            else{
                st.top().first->left=nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2) {
            st.top().second++;
            if (arr[idx] != -1) {
                st.top().first->right = new Node(arr[idx]);
                pair<Node*,int> rp={st.top().first->right,1};
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
vector<int> path;
vector<int> RootToNode(Node *node, int tar) {

    if(!node) return {};
    if(node->data == tar){
        return {tar};
    }
    vector<int> res;
    // path.push_back(node->data);
    if(node->data > tar) { 
        res = RootToNode(node->left, tar);
        if(!res.empty())
            res.push_back(node->data);
    }
    if(node->data < tar) { 
        res = RootToNode(node->right, tar);
        if(!res.empty())
            res.push_back(node->data);
    }
    return res;
    // if(node->data < tar) RootToNode(node->right, tar);
}
int ans;
int lca(Node* root,int a,int b){
//     Write your code here
/*
1. find node to root path for both values
and return first common values in the vector.
*/
/*
2. 
*/
    path.clear();
    vector<int> va, vb;

    va = RootToNode(root, a);
    // va = path;
    // path.clear();
    vb = RootToNode(root, b);
    // vb = path;    path.clear();
    int ans = 0;
    bool found = false;
    int sz = min(va.size(), vb.size());
    for(int i=0; i<sz; ++i){
        for(int j=i; j<sz; ++j){
            if(va[i] == vb[j]){
        // cout << va[i] << ' ' << vb[j] << endl;
                // ans = va[i];found=true;break;
                return va[i];
            }
            // if(found)break;
        }
    }
    // return va[0];
    // if(found)
    return a;
}

int lca_pep(Node* root, int a, int b) {

    if(root->data > a and root->data > b){
        lca_pep(root->left, a, b);
    } else if(root->data < a and root->data < b){
        lca_pep(root->right, a , b);
    } else{
        return root->data;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        if(x=="n"){
            arr[i]=-1;

        }
        else{
            arr[i]=stoi(x);
        }
    }
    int a,b;
    cin >> a >> b;
    Node* root= construct(arr);
    ans=root->data;
    ans = lca(root,a,b);
    cout << ans << endl;
    
}
