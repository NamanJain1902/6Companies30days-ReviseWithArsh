
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 1, r = 1;
        int n = nums.size();
        int ret = INT_MIN;
        
        for(int i=0; i<n; ++i){
            l = l * nums[i];
            r = r * nums[n - 1 - i];
            
            ret = max(ret, max(l, r));    
            
            if(l == 0) l = 1;
            if(r == 0) r = 1;
        }
        
        return ret;
    }
};






int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol. << endl;
    return 0;
}
    