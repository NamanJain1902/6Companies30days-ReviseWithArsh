#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int num) {
    int low = 0;
    int high = v.size()-1;
    int idx = -1;
    while(low < high) {
        int mid = low + (high - low) / 2;

        if(v[mid] == num) {
            return mid;
        }
        else if(v[mid] > num) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return high;
}

int longestSubsequence(int n, int arr[]) {

    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1; i<n; ++i) {
        
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
        } else {
            // int id = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            int id = binarySearch(temp, arr[i]);
            temp[id] = arr[i];
        }
    }
    return temp.size();
}
// TC: O(NlogN) SC: O(N)
int longestSubsequence(int n, int arr[]) {
    
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1; i<n; ++i) {
        
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
        } else {
            int id = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[id] = arr[i];
        }
    }
    return temp.size();
}

int printLongestIncreasingSubsequence(int n, int arr[]) {
    vector<int> dp(n+1, 1), hash(n+1, 0);

    for(int idx = 0; idx < n; ++idx) {
        hash[idx] = idx;
        for(int prev = 0; prev < idx; ++prev) {
            if(arr[idx] > arr[prev]) {
                if(dp[prev] + 1 > dp[idx]) {
                    dp[idx] = dp[prev] + 1;
                    hash[idx] = prev;
                }
            }
        }
    }
    
    int id;
    int idx = id = max_element(dp.begin(), dp.end()) - dp.begin();
    // cout << idx << " " << dp[idx] << endl;
    
    vector<int> lis;
    while(hash[idx] != idx) {
        lis.push_back(arr[idx]);
        idx = hash[idx];
    }
    lis.push_back(arr[idx]);
    reverse(lis.begin(), lis.end());

    // for(auto x: dp) cout << x << " ";cout << endl;
    // for(auto x: lis) {cout << x << " ";}cout << endl;
    // for(auto x: hash) {cout << x << " ";}cout << endl;

    return dp[id];
}

// TC: O(N^2) SC: O(2 * N)
int longestIncreasingSubsequence1(int n, int arr[]) {
    // 1. write the base case
    // 2. reverse  order or changing parameters
    // 3. copy the recurrence
    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);
        
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --) {
            int notTake = 0 + next[prev_index +1];
            int take = 0;
    
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                take = 1 + next[ind + 1];
            }
            // dp[ind][prev_index+1] = max(notTake,take);
            curr[prev_index+1] = max(notTake, take);
        }
        next = curr;
    }
    
    return next[0];
}

// TC: O(N^2) SC: O(N ^ 2)
int longestIncreasingSubsequence0(int arr[], int n) {
    // 1. write the base case
    // 2. reverse  order or changing parameters
    // 3. copy the recurrence
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    
    for(int i=n-1; i>=0; --i) {
        for(int prev_idx = i-1; prev_idx>=-1; --prev_idx) {
            int len = 0 + dp[i+1][prev_idx+1];
            if(prev_idx == -1 || arr[i] > arr[prev_idx]) {
                len = max(len, dp[i+1][prev_idx+1]);
            }
            dp[i][prev_idx+1] = len;
        }
    }
    return dp[0][0];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(auto &x: arr) cin >> x;
    cout << printLongestIncreasingSubsequence(n, arr) << endl;
}