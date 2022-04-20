#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, pair<int, int> *tree, int start, int end, int treeNode) {

    if(start == end){
        tree[treeNode].first = arr[start];
        tree[treeNode].second = INT_MIN;
        return;
    }

    int mid = start + (end - start) / 2;

    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2 * treeNode + 1);

    tree[treeNode].first  = max(tree[2*treeNode].first, tree[2*treeNode+1].first);
    tree[treeNode].second = min(max(tree[2*treeNode].first, tree[2*treeNode+1].second), 
                                max(tree[2*treeNode].second, tree[2*treeNode+1].first));
}

void updateTree(int *arr, pair<int, int> *tree, int start, int end, int treeNode, int idx, int value) {

    int mid = start + (end - start) / 2;

    if(mid == start){
        arr[idx] = value;
        tree[treeNode].first = arr[idx];
        return;
    }
    if(start == end) return;

    updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);

    tree[treeNode].first  = max(tree[2*treeNode].first, tree[2*treeNode+1].first);
    tree[treeNode].second = min(max(tree[2*treeNode].first, tree[2*treeNode+1].second), 
                            max(tree[2*treeNode].second, tree[2*treeNode+1].first));
}

pair<int, int> queryTree(pair<int, int> *tree, int start, int end, int treeNode, int L, int R) {

    // completly outside scope
    if(start > R || end < L){
        return {INT_MIN, INT_MIN};
    }
    // completely inside scope
    if(start >= L && end <= R){
        return tree[treeNode];
    }
    // partially inside and partially outside
    int mid = start + (end - start) / 2;
    pair<int, int> lans = queryTree(tree, start, mid, 2*treeNode, L, R);
    pair<int, int> rans = queryTree(tree, mid+1, end, 2*treeNode+1, L, R);

    pair<int, int> ans;
    ans.first  = max(lans.first, rans.first);
    ans.second = min(max(lans.first, rans.second), max(lans.second, rans.first));
    return ans;
}


int main(){
    int n;
    cin >> n;

    // int *arr = int[n];
    // pair<int,int> *tree = int[4*n+1];
    int arr[n];
    pair<int, int> tree[2*n+1];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    buildTree(arr, tree, 0, n-1, 1);
    int q; 
    cin >> q;
    while(q--){
        char ch;cin>>ch;
        int a, b;cin>>a>>b;
        if(ch == 'U'){
            updateTree(arr, tree, 0, n-1, 1, a-1, b);
        }
        else if(ch == 'Q'){
            pair<int, int> maxPair = queryTree(tree, 0, n-1, 1, a-1, b-1);
            cout << maxPair.first + maxPair.second << "\n";
        }
    }
    return 0;
}
