#include<bits/stdc++.h>
using namespace std;

struct Node {
    int sth, cow;
};


void buildTree(Node *arr, Node *tree, int start, int end, int treeNode) {
    
    if(start == end) {
        tree[treeNode].sth = arr[start].sth;
        tree[treeNode].cow = arr[start].cow;
        return;
    }

    int mid = start + (end - start) / 2;

    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    // int str, cow;
    Node lret = tree[2*treeNode];
    Node rret = tree[2*treeNode+1];

    if(lret.str != rret.str) {
        if(lret.str > rret.str){
            tree[treeNode] = lret;
        } else {
            tree[treeNode] = rret;
        }
    } else {
        if(lret.cow != rret.cow) {
            if(lret.cow < rret.cow){
                tree[treeNode] = lret;
            } else {
                tree[treeNode] = rret;
            }
        } else {
            tree[treeNode] = lret;
        }
    }
}


int queryTree(Node *tree, int start, int end, int treeNode, int L, int R) {

    // completly outside given range --> return 0
    if(start > R || end < L){
        return INT_MAX;
    }

    // completly inside given range --> return value
    if(start >= L && end <= R) {
        return tree[treeNode];
    }

    // if partially inside and partially outside the range.
    int mid = start + (end - start) / 2;
    Node lret  = queryTree(tree, start, mid, 2 * treeNode, L, R);
    Node rret  = queryTree(tree, mid+1, end, 2*treeNode+1, L, R);

}


int main()
{
    int n, q;
    cin >> n;
    Node *arr = new Node[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i].sth;
    }
    for(int i=0; i<n; ++i){
        cin >> arr[i].cow;
    }
    cin >> q;
    Node *tree = new Node[4*n+1];
    buildTree(arr, tree, 0, n-1, 1);

    for(int i=0; i<q; ++i){
        int a, b; cin >> a >> b;

        cout << queryTree(tree, 0, n-1, 1, a-1, b-1).num_of_evens << "\n"; 
    }
    for(int i=0; i<(4*n+1); ++i) {
        cout << "(" << tree[i].num_of_evens << ", " << tree[i].num_of_odds << ")" << "\n";
    }
    puts("");
    return 0;
}
