#include <bits/stdc++.h>
using namespace std;
 
int sortK(int arr[], int n, int k){

//write your code here
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<n; ++i) {
        min_heap.push(arr[i]);
    }
    for(int i=0; i<n; ++i) {
        cout << min_heap.top() << "\n";
        min_heap.pop();
    }
}
// like a funnel
int sortK1(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<=k; ++i){
        pq.push(arr[i]);
    }

    for(int i=k+1; i<n; ++i){
        cout << pq.top() << "\n";
        pq.pop();
        pq.push(arr[i]);
    }
    while(pq.size() > 0) {
        cout << pq.top() << "\n";
        pq.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i<n ; i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    int k;
    cin>>k;
    sortK(arr, n, k);
    return 0;
}