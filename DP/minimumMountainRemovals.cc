#include<bits/stdc++.h>
using namespace std;


int minimumMountainRemovals(vector<int> &nums){
    int n = nums.size();
    vector<int> lis(n, 1), lds(n, 1);

    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(nums[i] > nums[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        } 
    }

    for(int i=n-1; i>=0; --i){
        for(int j=n-1; j>i; --j){
            if(nums[i] > nums[j]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }   


    int omax = 0;
    for(int i=0; i<n; ++i){
        omax = max(lis[i]+lds[i]-1, omax);
    }
    return omax;
}



int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(auto &x: nums)cin>>x;
    cout << minimumMountainRemovals(nums) << endl;
    return 0;
}

