#include<bits/stdc++.h>
using namespace std;
int arr[5014];
struct node{
    int counte=0;
    int counto=0;
};
node *tree=new node[5014];

void buildTree(int start,int end,int tn){
    if(start==end){
        if(arr[start]%2==0){
            tree[tn].counte=1;
            tree[tn].counto=0;
        } else {
            tree[tn].counto=1;
            tree[tn].counte=0;
        }
        return;
    }
    int mid = (start+end)/2;
    buildTree(start,mid,tn*2);
    buildTree(mid+1,end,tn*2+1);

    tree[tn].counte = tree[tn*2].counte+tree[tn*2+1].counte;
    tree[tn].counto = tree[tn*2].counto+tree[tn*2+1].counto;
    return;
}
void update(int start,int end,int tn,int id,int val){
    if(start == end){
        arr[id] = val;
        if(arr[id]%2==0) {
            tree[tn].counte=1;
            tree[tn].counto=0;
        }else {
            tree[tn].counto=1;
            tree[tn].counte=0;
        }
        return;
    }
    int mid = (start + end)/2;
    if(id > mid) {
        update(mid+1,end,2*tn+1,id,val);
    }
    else {
        update(start,mid,2*tn,id,val);
    }
    tree[tn].counte = tree[tn*2].counte+tree[tn*2+1].counte;
    tree[tn].counto = tree[tn*2].counto+tree[tn*2+1].counto;
    return;

}
node query(int start,int end,int tn,int l,int r){
    node result;
    result.counte=0;
    result.counto=0;
    
    if(start>r||end<l){
        return result;
    }
    if(start>=l && end<=r){
        return tree[tn];
    }
    int mid = (start+end)/2;
    if(l>mid){
        return query(mid+1,end,tn*2+1,l,r);
    }if(r<=mid){
        return query(start,mid,tn*2,l,r);
    }

    node left = query(start,mid,tn*2,l,r);
    node right = query(mid+1,end,tn*2+1,l,r);

    result.counte = left.counte+right.counte;
    result.counto = left.counto+right.counto;

    return result;
}

int main() {
    // Write your code here
    int n,q,ch,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    cin>>q;
    buildTree(0,n-1,1);
 
    for(int i=0;i<q;i++){
        cin>>ch>>x>>y;
        if(ch==0){
            update(0,n-1,1,x-1,y);
        }
        else{
            node ans = query(0,n-1,1,x-1,y-1);
            if(ch==2){
                cout<<ans.counto<<endl;
            }
            else if(ch==1){
                cout<<ans.counte<<endl;
            }
        }

}

return 0;

}