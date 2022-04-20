#include<bits/stdc++.h>
using namespace std;
struct node{
    int msum;
    int sum;
    int bps;
    int bss;
};
void buildtree(int *arr,node *tree,int start,int end,int treenode)
{
    if(start==end)
    {
        tree[treenode].sum  = arr[start];
        tree[treenode].msum = arr[start];
        tree[treenode].bps  = arr[start];
        tree[treenode].bss  = arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,treenode*2);
    buildtree(arr,tree,mid+1,end,treenode*2+1);
    tree[treenode].sum  = tree[treenode*2].sum+tree[treenode*2+1].sum;
    tree[treenode].bps  = max(tree[treenode*2].bps,tree[treenode*2].sum+tree[treenode*2+1].bps);
    tree[treenode].bss  = max(tree[treenode*2+1].bss,tree[treenode*2+1].sum+tree[treenode*2].bss);
    tree[treenode].msum = max(tree[treenode*2].msum,max(tree[treenode*2+1].msum,max(tree[treenode*2].sum+tree[treenode*2+1].bps,max(tree[treenode*2+1].sum+tree[treenode*2].bss,tree[treenode*2].bss+tree[treenode*2+1].bps))));
}

node query(node *tree,int start,int end,int treenode,int left,int right)
{
    if(right<start || left>end )
    {
    node x;
    x.msum=0;
    x.sum=0;
    x.bps=0;
    x.bss=0;
    return x;    
    }
    
    if(start>=left && end<=right)
    return tree[treenode];
    
    int mid=(start+end)/2;
    node ans1   = query(tree,start,mid,treenode*2,left,right);
    node ans2   = query(tree,mid+1,end,treenode*2+1,left,right);
    node ans;
    ans.sum     = ans1.sum+ans2.sum;
    ans.bps     = max(ans1.bps,ans1.sum+ans2.bps);
    ans.bss     = max(ans2.bss,ans2.sum+ans1.bss);
    ans.msum    = max(ans1.msum,max(ans2.msum,max(ans1.sum+ans2.bps,max(ans2.sum+ans1.bss,ans1.bss+ans2.bps))));
    return ans;
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
     node *tree=new node[4*n];
    buildtree(A,tree,0,n-1,1);
    int q;
    cin>>q;
    //for(int i=1;i<3*n;i++)
        //cout<<tree[i].maxi<<" "<<tree[i].smaxi<<endl;
    for(int i=0;i<q;i++)
    {
        
        int x,y;
        cin>>x>>y;
        
            node ans=query(tree,0,n-1,1,x-1,y-1);
            int k=ans.msum;
           
            cout<<k<<endl;
           
        
    }
    return 0;
}