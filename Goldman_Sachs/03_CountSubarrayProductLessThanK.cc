#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            if(k <= 1 || nums.size() == 0)  return 0;

            int prod = 1;
            int res = 0;
            int left = 0;
            int right = 0;
            int n = nums.size();

            while(right < n){
                prod *= nums[right];

                while(prod >= k){
                    prod /= nums[left];
                    left++;
                }

                res += (right - left + 1);
                right++;
            }

            return res;


        }
        int countSubArrayProductLessThanK0(const vector<int>& a, int n, long long k) {


            int  cnt = 0;

            for(int i=0; i<n; ++i){
                int p = 1;
                bool cool = true;

                for(int j=i; j>=0; --j){
                    p *= a[j];


                    if(p >= k){
                        cool = false;
                        break;
                    }else{
                        cnt++;
                        //                    cout << p << endl;
                    }

                }
                //cout << p << endl;

                //if(cool){
                //   cnt++;
                //}
            }

            return cnt;
        }
};


int  main(){
    Solution sol;
    int n;cin>>n;
    vector<int> a(n);
    for(auto &x: a)cin>>x;
    int k;cin>>k;

    cout << sol.numSubarrayProductLessThanK(a, k) << endl;

    return 0;
}
