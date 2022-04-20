#include<bits/stdc++.h>
using namespace std;


struct Node{
    int num_of_evens;
    int num_of_odds;
};

void buildTree(int *arr, Node *tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode].num_of_evens = (arr[start] %2 ==0);
        tree[treeNode].num_of_odds  = arr[start] & 1;
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode].num_of_evens = tree[2*treeNode].num_of_evens + tree[2*treeNode+1].num_of_evens;
    tree[treeNode].num_of_odds  = tree[2*treeNode].num_of_odds  + tree[2*treeNode+1].num_of_odds;
}

Node queryTree(Node *tree, int start, int end, int treeNode, int L, int R) {
    Node result;
    result.num_of_odds = result.num_of_evens =  0;
    
    // completly outside given range --> return 0
    if(start > R || end < L){
        return result;
    }
    
    // completly inside given range --> return value
    if(start >= L && end <= R) {
        return tree[treeNode];
    }
    
    // if partially inside and partially outside the range.
    int mid   = start + (end - start) / 2;
    if(L >= mid){
        return queryTree(tree, start, mid, 2 * treeNode, L, R);
    }
    if(R < mid) {
        return queryTree(tree, mid+1, end, 2*treeNode+1, L, R);
    }
    Node lans = queryTree(tree, start, mid, 2 * treeNode, L, R);
    Node rans = queryTree(tree, mid+1, end, 2*treeNode+1, L, R);

    result.num_of_evens = lans.num_of_evens + rans.num_of_evens;
    result.num_of_odds  = lans.num_of_odds + rans.num_of_odds;
    return result;
}

void updateTree(int *arr, Node *tree, int start, int end, int treeNode, int idx, int value) {
    if(idx == treeNode) {
        arr[idx] = value;
        tree[idx].num_of_evens = (value %2==0);
        tree[idx].num_of_odds  =   value & 1;
        return;
    }

    int mid = start + (end - start) / 2;
    if(idx > mid) {
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    } else {
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    }
    tree[idx].num_of_evens = tree[2*idx].num_of_evens + tree[2*idx+1].num_of_evens;
    tree[idx].num_of_odds  = tree[2*idx].num_of_odds  + tree[2*idx+1].num_of_odds;
    return;
}

int main()
{
    int n, q;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    cin >> q;
    Node *tree = new Node[4*n+1];
    buildTree(arr, tree, 0, n-1, 1);

    for(int i=0; i<q; ++i){
        int type; cin >> type;
        int a, b; cin >> a >> b;
        /**
         * 0 : update a-1 to b.
         * 1 : count number of even numbers in range l to r inclusive.
         * 2 : count number of odd numbers in range l to r inclusive.
        */
        if(type == 1) {
            for(int i=0; i<(4*n+1); ++i) {
                cout << "(" << tree[i].num_of_evens << ", " << tree[i].num_of_odds << ")" << "\n";
            }   
            cout << queryTree(tree, 0, n-1  , 1, a-1, b-1).num_of_evens << "\n"; 
        } else if(type == 2) {
            cout << queryTree(tree, 0, n-1, 1, a-1, b-1).num_of_odds << "\n";  
        } else if(type == 0) {
            updateTree(arr, tree, 0, n-1, 1, a-1, b);
        }
    }
    for(int i=0; i<(4*n+1); ++i) {
        cout << "(" << tree[i].num_of_evens << ", " << tree[i].num_of_odds << ")" << "\n";
    }
    puts("");
    return 0;
}
