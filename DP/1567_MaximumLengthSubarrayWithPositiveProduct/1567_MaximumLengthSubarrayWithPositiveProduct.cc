
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int brute(vector<int> &nums) {
        int n = nums.size();
        int maxlen = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                int p = 1, len = 0;            
                for(int k=i; k<=j; ++k){
                    p *= nums[k];
                    len++;
                }
                if(p > 0)
                    maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int maxlen = -1;
        for(int i=0;i <n; ++i) {

            int j, c_neg = 0, f_neg = -1, l_neg = -1, p = 0;

            for(j=i; j<n and nums[j] != 0; ++j)  {
                if(nums[j] < 0 and f_neg < 0) f_neg = j;
                if(nums[j] < 0) l_neg = j, c_neg++;
                if(nums[j] > 0) p++;
            }

            if(c_neg & 1) {
                maxlen = max(maxlen, l_neg - i); // considering subarray from i to l_neg-1
                maxlen = max(maxlen, j - f_neg - 1);
            } else {
                maxlen = max(maxlen, j - i);
            }
            i=j;
        }
        return maxlen;
    }
    int getMaxLen(vector<int>& nums) {        
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int first_negative_index = 0;
        int  last_negative_index = 0;
        bool fl=false, fr=false;
        int cneg = 0;
        
        while(l < r) {
            if(nums[l] < 0 or nums[r] < 0) {
                cneg += 1;
            }
            if(!fl and nums[l] < 0) {
                first_negative_index = l;
                fl = true;
            }
            if(!fr and nums[r] < 0) {
                last_negative_index = r;
                fr = true;
            }
            l++;
            r--;
        }
        
        if(cneg & 1) {
            return max(n - first_negative_index, last_negative_index);
        } else {
            return n;
        }
        return 0;
    }
};



int main(){
    // int n;
    // cin >> n;
    vector<int> v = {0,1,-2,-3,-4};
    Solution sol;
    cout << sol.getMaxLen(v) << endl;
    return 0;
}
    