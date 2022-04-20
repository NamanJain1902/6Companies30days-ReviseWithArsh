#include<bits/stdc++.h>
using  namespace std;


void buildTree(int *arr, int *tree, int start, int end, int treeNode) {

    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode] = max(tree[2*treeNode], tree[2*treeNode+1]);
}

int queryTree(int *tree, int start, int end, int treeNode, int L, int R){

    if(start > R || end < L){
        return INT_MIN;
    }

    if(start >= L and end <= R){
        return tree[treeNode];
    }

    // partially inside and partially outside.
    int mid = start + (end - start) / 2;
    int lans = queryTree(tree, start, mid, 2*treeNode, L, R);
    int rans = queryTree(tree, mid+1, end, 2*treeNode+1, L, R);

    return max(lans, rans);
}
int main()
{
    int n;
    cin  >> n;
    int* arr = new int[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    int *tree = new int[4*n+1];
    buildTree(arr, tree, 0, n-1, 1);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << queryTree(tree, 0, n-1, 1, l, r) << endl;
    }
}