#include<unordered_set>
#include<algorithm>
#include<cstring>

int sm;
int dp[101][101][101];
bool recursive(vector<int> &arr, unordered_set<int> partition1, unordered_set<int> partition2, int idx, int sum1, int sum2)  {
    
    if(sum1 > sm or sum2 > sm) return false;
    if(idx == arr.size()) {
        if(sum1 == sum2) {
            return true;
        }
        return false;
    }
    if(dp[idx][sum1][sum2] != -1) return dp[idx][sum1][sum2];
    
    partition1.insert(idx);
    sum1 += arr[idx];
    bool inpart1 = recursive(arr, partition1, partition2, idx + 1, sum1, sum2);
    partition1.erase(idx);
    sum1 -= arr[idx];
    
    partition2.insert(idx);
    sum2 += arr[idx];
    bool inpart2 = recursive(arr, partition1, partition2, idx + 1, sum1, sum2);
    partition2.erase(idx);
    sum2 -= arr[idx];
    
    return dp[idx][sum1][sum2] = (inpart1 or inpart2);
}

bool canPartition(vector<int> &arr, int n)
{
	/*
        approach : if we can find sum / 2 
    */
    sm = accumulate(arr.begin(), arr.end(), 0);
    if(sm & 1) return false;
    
    // sum of a partition
    int target_partition_sum = sm / 2;
    
//     int dp[n+1][target_partition_sum+1];
//     int prev[n+1]{0}, curr[n+1]{0};
    vector<int> prev(target_partition_sum+1, 0), curr(target_partition_sum+1, 0);
    prev[0] = curr[0] = 1;
//     if(arr[0] <= target_partition_sum) prev[arr[0]] = 1;
    
    for(int i=0; i<n; ++i) {
        for(int target=1; target<=target_partition_sum; target++) {
            int not_take = prev[target];
            int take = false;

            if(arr[i] <= target) take = prev[target - arr[i]];
            curr[target] = take | not_take;
        }
        prev = curr;
    }
    
    return prev[target_partition_sum];
//     unordered_set<int> partition1, partition2;
//     int sum1 = 0, sum2 = 0;
//     memset(dp, -1, sizeof(dp));
    
//     return recursive(arr, partition1, partition2, 0, sum1, sum2);
}

