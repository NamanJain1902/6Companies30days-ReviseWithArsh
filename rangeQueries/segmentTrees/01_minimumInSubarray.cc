#include<bits/stdc++.h>
using namespace std;


void buildTree(int *arr, int *tree, int start, int end, int treeNode) {

    if(start == end) {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = start + (end - start) / 2;

    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value){

    int mid = start + (end - start) / 2;

    if(mid == idx){
        arr[idx] = value;
        tree[idx] = value;
        return;
    }
    
    if(idx > mid){
        updateTree(arr, tree, mid+1, end, 2 * treeNode + 1, idx, value);
    } else {
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    }
    tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

int queryTree(int *tree, int start, int end, int treeNode, int L, int R) {

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
    int lans = queryTree(tree, start, mid, 2 * treeNode, L, R);
    int rans = queryTree(tree, mid+1, end, 2*treeNode+1, L, R);
    return min(lans, rans);
}

int main()
{
    int n, q;
    cin >> n >> q;
//     int *arr=new int[n];

    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    int tree[4*n + 1]{0};
    buildTree(arr, tree, 0, n-1, 1);

    // for(int i=1; i<(int)4*n; ++i){
    //     cout << tree[i] << " ";
    // }
    // puts("");

    for(int i=0; i<q; ++i){
        char type; cin >> type;
        int a, b; cin >> a >> b;

        if(type == 'q') {
            int minValue = queryTree(tree, 0, n-1, 1, a-1, b-1);
            cout << minValue << endl;
        } else if(type == 'u') {
            updateTree(arr, tree, 0, n-1, 1, a-1, b);
        }
    }
}
