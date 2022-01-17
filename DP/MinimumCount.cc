// Minimum number of squares whose sum equals to given number n
#include<bits/stdc++.h>
using namespace std;

// misinterpreted the question, won't work here.
int brute_formula(int tar){
    // using sum of squares formula
    int i = 1;

    while(true){
        int nc = i * i * i;
        int ns = i * i;

        if((2 * nc + 3 * ns + i) == (6 * tar)) return i;
        i++;
    }
    
}
//vector<int> dp;
int *dp;
int rec(int n){
     // base cases
    // if n is perfect square then
    // Minimum squares required is 1
    // (144 = 12^2)
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if(n <= 3){
        return n;
    }
    cout << n << endl;
    if(dp[n] != -1)return dp[n];
    int ans = n;
    for(int i=1; i<=n; ++i){
        int sq = i * i;
        if(sq > n) break;
        ans = min(ans, rec(n - sq) + 1);
        dp[n] = ans;
    }
    return ans;
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    //dp.resize(n+1, -1);
    dp = new int[n+1];
    for(int i=0; i<=n; ++i) dp[i]=-1;
    cout << argv[1] << endl;
 //   cout << "DP SIZE " << dp.size() << endl;
    cout  << dp[0] << endl;
    cout << rec(n) << endl;
    delete[] dp; 
    cout  << dp[0] << endl;
  //  dp.clear();
  //  cout << "DP SIZE " << dp.size() << endl;
    return 0;
}
