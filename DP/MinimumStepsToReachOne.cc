#include<bits/stdc++.h>
using namespace std;


// Approach 1
int largestDivisor(int n){
    if(n % 2 == 0)return n/2;
    for(int i=n/2-1; i>=(int)sqrt(n); --i){
        if(n%i == 0)return i;
    }
    return 1;
}


// Approach 2
int largestDivisor2(int n){
    
    // if i is divisor of n, then n / i will
    // be its bigger divisor
    for(int i=2; i*i<n; ++i){
        if(n%i==0) return n/i;
    }
}

int rec(int n, int *dp){
    
    if(n <= 1) return 0;
    cout << n << "\t" << dp[n] << endl;
    if(dp[n] != -1) return dp[n];
    int nBiggestDivisor = INT_MAX;
    int val = largestDivisor(n);
    if(val != 1)
        nBiggestDivisor = rec(val, dp);
   
    int minus1 = rec(n - 1, dp);
    cout << n << "\t" << minus1 << "\t" << nBiggestDivisor << "\t" << val << "\t" << dp[n] << endl;
    
    return dp[n] = min(minus1, nBiggestDivisor) + 1;
}

struct data
{
    int val;
    int steps;
    data(int val, int steps) : val(val), steps(steps)
    {}
};

//  method returns minimum step to reach one
int minStepToReachOne(int N)
{
    queue<data> q;
    q.push(data(N, 0));

    // set is used to visit numbers so that they
    // won't be pushed in queue again
    set<int> st;

    //  loop until we reach to 1
    while (!q.empty())
    {
        data t = q.front();     q.pop();

        // if current data value is 1, return its
        // steps from N
        if (t.val == 1)
            return t.steps;

        //  check curr - 1, only if it not visited yet
        if (st.find(t.val - 1) == st.end())
        {
            q.push(data(t.val - 1, t.steps + 1));
            st.insert(t.val - 1);
        }

        //  loop from 2 to sqrt(value) for its divisors
        for (int i = 2; i*i <= t.val; i++)
        {

            // check divisor, only if it is not visited yet
            // if i is divisor of val, then val / i will
            // be its bigger divisor
            if (t.val % i == 0 && st.find(t.val / i) == st.end())
            {
                q.push(data(t.val / i, t.steps + 1));
                st.insert(t.val / i);
            }
        }
    }
}
int main(){
    int n;cin>>n;
    int *dp = new int[n+1];
    for(int i=0; i<=n; ++i)dp[i]=-1;
    
    //int ans = rec(n, dp);
    int ans = minStepToReachOne(n);
    cout  << ans << endl;
    return 0; 
}

