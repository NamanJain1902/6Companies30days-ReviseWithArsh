#include<bits/stdc++.h>
using namespace std;


// returns index where target is found
int binary_search(vector<int> &dp, int target){

    int low = 0; int high= dp.size();
    while(low <= high){
        int  mid = low + (high - low)/2;

        if(dp[mid] == target){
            return mid;
        } else if(dp[mid] > target){
            high = mid - 1 ;
        } else{
            low = mid + 1 ;
        }
    }
    return low;
}

int maxEnvelopes(vector<vector<int>>& envelopes) {

    sort(envelopes.begin(), envelopes.end(), [&](vector<int> a, vector<int> b){
                return a[0] < b[0] || (a[0] == b[0] and a[1] < b[1]);
                });
    int n = envelopes.size();
    vector<int> dp;
    int cnt = 0;

    for(int i=0; i<n; ++i){
        int cur = envelopes[i][1];

        auto itr = lower_bound(dp.begin(), dp.end(), cur);

        if(itr == dp.end()){
            dp.push_back(cur);
        } else if(*itr > cur){
            dp[itr - dp.begin()] = cur;
        }
    }
    return dp.size();
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> evs(n, vector<int>(2, 0));

    for(auto &x: evs){
        cin >> x[0] >> x[1];
    }

    cout << maxEnvelopes(evs) << endl;

}
