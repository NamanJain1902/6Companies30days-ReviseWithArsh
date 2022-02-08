#include<bits/stdc++.h>
using namespace std;


vector<int> parent;
bool find(int child){

    while(child != parent[child]){
        parent[child] = parent[parent[child]];
        child = parent[child];
    }
    return child;
}

void _union(int A, int B){
    int rootA = find(A);
    int rootB = find(B);

    if(rootA != rootB){
        if(ranks[rootA] > ranks[rootB]){
            parent[rootB] = rootA:
        } else if(ranks[rootB] < ranks[rootA]){
            parent[rootA] = rootB;
        } else{
            parent[rootA] = rootB;
            ranks[rootB] += 1;
        }
    }
}


int main()
{

}