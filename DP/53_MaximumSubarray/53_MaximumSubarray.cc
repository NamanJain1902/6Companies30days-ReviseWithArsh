
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int max(int a, int b){
        return (a >= b ? a : b);
    }
    int maxSubArray(vector<int>& nums) {
        long long maxsum = INT_MIN;
        int n = nums.size();
        long long tradition = 0;\
            
        for(int i=0; i<n; ++i) {
            
            if(tradition + nums[i] > 0) {  
                tradition = max(tradition + nums[i], nums[i]);
            } else {
                tradition = nums[i];
            }          
            maxsum = max(maxsum, tradition);
        }
        
        return maxsum;


        int mx = INT_MIN;
        rec(nums, 0, mx, 0);
        return mx;            
    }

    void rec(vector<int> &nums, int sum, int &mx, int idx) {
        
        if(idx == nums.size()) {
            return;
        }
        
        sum += nums[idx];
        mx = max(sum, mx);
        if(sum < 0){
            sum = 0;
        }
        
        rec(nums, sum, mx, idx + 1);
    }
};



int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol. << endl;
    return 0;
}
    