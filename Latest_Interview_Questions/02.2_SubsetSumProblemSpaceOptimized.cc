#include <bits/stdc++.h>
using namespace std;


bool isPossible(int elements[], int sum, int n)
{
    int dp[sum + 1];
    dp[0] = 1;
    
    // Loop to go through every element of
    // the elements array
    for(int i = 0; i < n; i++)
    {
        
        // To change the values of all possible sum
        // values to 1
        for(int j = sum; j >= elements[i]; j--) 
        {
            if (dp[j - elements[i]] == 1)
                dp[j] = 1;
        }
    }
    
    // If sum is possible then return 1
    if (dp[sum] == 1)
        return true;
        
    return false;
}

bool isSubsetSum(vector<int> &arr, int n, int sum)
{
    bool subset[2][sum + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {

            // A subset with sum 0 is always possible 
            if (j == 0)
                subset[i % 2][j] = true; 
            else if (i == 0)
                subset[i % 2][j] = false; 
            else if (arr[i - 1] <= j)
                subset[i % 2][j] = subset[(i + 1) % 2][j - arr[i - 1]] || subset[(i + 1) % 2][j];
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j];
        }
    }

    return subset[n % 2][sum];
}
/*
bool subset[2][101];

bool isSubsetSumSpaceOpt(vector<int> &v, int n, int sm){

    subset[0][0] = true;
    for(int i=0; i<n; ++i){

        for(int j=0; j<=sm; ++j){
            
            if(v[i] > j){
                subset[1][j] = subset[i-1][j];
            } else {
                subset[1][j] = (subset[0][j] || subset[0][j - v[i]]);
            }
        }

        subset[0] = subset[1];
    }


    return subset[1][sm];
}
*/


bool isSubsetSum0(vector<int> &v, int n, int sm){
    vector<int> dp(sm+1); // boolean array

    dp[0] = 1;

    for(int i=0; i<n; ++i){
        // to change the values of all possible sum values to 1.
        for(int j=sm;  j>= v[i]; j--){
            if(dp[j - v[i]] == 1){
                dp[j] = 1;
            }
        }
    }

    if(dp[sm] == 1){
        return true;
    }
    return false;
}


int main()
{
    vector<int> elements = { 6, 2, 5 };
    int sum = 7;

    if (isSubsetSum(elements, elements.size(), sum))
        cout << ("YES") << endl;
    else
        cout << ("NO") << endl;

    return 0;
}
