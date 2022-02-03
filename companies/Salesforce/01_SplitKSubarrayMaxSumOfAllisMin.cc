#include<bits/stdc++.h>
using namespace std;
/**
 * @author Naman Jain
 * 
 * @link https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/ @endlink
 * 
 * @brief Given an Array[] of N elements and a number K. ( 1 <= K <= N ) . Split the given array into K 
            subarrays (they must cover all the elements). The maximum subarray sum achievable out of K subarrays 
            formed, must be the minimum possible. Find that possible subarray sum.
 */

int ans = INT_MAX;
void bkt(vector<int> &v, int n, int k, int idx, int sm, int mxsm){

    if(k == 1){
        mxsm = max(mxsm, sm);
        sm = 0;

        for(int i=idx; i<n; ++i){
            sm += v[i];
        }
        mxsm = max(mxsm, sm);
        ans = min(mxsm, ans);
        return;
    }
    sm = 0;

    // using for loop to divide the array into k subarrays
    for(int i=idx; i<n; ++i){
        sm += v[i];

        mxsm = max(mxsm, sm);

        bkt(v, n, k - 1, i + 1, sm, mxsm);
    }
}

void temp(int *arr, int n){
    sort(arr, arr+n);
    for(int i=0; i<n; ++i)cout<<arr[i]<<' ';
    puts("");
}
int *findTwoElement(int *arr, int n) {
        int A, B;
        // for(int i=0; i<n; ++i)cout<<arr[i]<<' ';cout<<endl;
        sort(arr, arr+n);
        for(int i=0; i<n; ++i)cout<<arr[i]<<' ';cout<<endl;
        
        for(int i=1, idx=0; idx < n; ++i, idx++) {
            if(arr[idx] == arr[idx+1] || (idx>=1 ? arr[idx] == arr[idx-1] : true)) {
                B = arr[idx];
                
                if(arr[idx] != i){
                    cout << i << endl;
                    A = i;
                }
                // break; 
                continue;
            }
            else if(arr[idx] != i) {
                A = arr[idx];
            }
        }
        
        
        // for(int i=0; i<n; ++i){
        //     if(arr[i] != (i+1)){
        //         A = i + 1;
        //         break;
        //     }
        // }

        
        
        int narr[2] = {B, A};
        int *ptr = narr;
        return ptr;
}
void asdf(vector<int> &v){
    int n = v.size();
    
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n, 0);
    assert(n >= k);

    int arr[n];
    for(int i=0; i<n; ++i)cin>>arr[i];

    auto ans = findTwoElement(arr, n);
    cout << ans[0] << ' ' << ans[1] << endl;
    // for(auto &x: v)cin>>x;
    // bkt(v, n, k, 0, 0, 0);
    // cout << ans << endl;
}
