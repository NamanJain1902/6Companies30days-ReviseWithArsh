// Minimum number of squares whose sum equals to given number n
/*
Check All
https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/

*/

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

int numSquares(int n){
    // creating visited vector of size n+1;
    vector<int> visited(n+1, 0);

    queue<pair<int, int>>  q;

    int ans = INT_MAX;

    // push starting node with 0
    // 0 indicate current number
    // of steps to reach n
    q.push({n, 0});

    // mark starting node visited
    visited[n] = 1;

    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();

        if(u.first == 0)ans=min(ans, u.second);

        // loop for all possible path from
        // from 1 to i*i <= current node(u.first)
        for(int i=1; i*i<=u.first; i++){
            // if we are standing at some node
            // then next node it can jump to will
            // be current node - (some sq. less than or equal n)
            int path = (u.first - (i*i));

            // check if it's valid and not visited yet
            if(path >= 0 && (!visited[path] || path == 0)){
                // mark visited
                visited[path] = 1 ;

                // pust it in queue
                q.push({path, u.second + 1});
            }
        }
    }
    // Return ans to the calling funtion
    return ans;
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
    cout << numSquares(n) << endl;
    return 0;
}
