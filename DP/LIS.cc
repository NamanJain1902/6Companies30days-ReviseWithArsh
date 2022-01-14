#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
        vector<int> s;
        for(auto x: nums){
            if(s.size() == 0)
                s.push_back(x);
            else if (s[s.size() - 1] < x){
                s.push_back(x);
            }
            else{
                int j = s.size() - 1;
                while(j >= 0 && s[j] >= x)
                    j --;
                s[j + 1] = x;
            }
        }
        return s.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }


    vector<int> dp(n, 0);
    dp[0] = 1;
    int omax=INT_MIN;

    for(int i=0; i<n; ++i){
        int mxf=0;
        for(int j=0; j<i; ++j){
            if(v[i] > v[j]){
                if(dp[j] > mx)
                    mx = dp[j];
            }
        }
        dp[i] = mx + 1;
        omax =  max(dp[i], omax);
    }


    cout << omax << endl;

}
