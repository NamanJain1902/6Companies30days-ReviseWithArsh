#include<bits/stdc++.h>
using namespace std;

int dp[101][101][2];

// x -> sum of digit
int solve(string &num, int n, int x, bool tight) {

    if ( n == 0 ) {
        if x == 0 return 1;
        else return 0;
    }
    if(x < 0) return 0;
    if(n == 1) {
        if(x >= 0 and x <= 9) return 1;
        return 0;
    }
    if(dp[n][x][tight] != -1) {
        return dp[n][x][tight];
    }
    int answer = 0;
    int ub = tight ? (nums[nums.length() - n] - '0') : 9;

    for(int digit = 0; digit <= ub; ++digit) {
        // fix the nth digit
        answer += solve(R, n - 1, x - dig, (tight & (digit == ub)));
    }

    return dp[n][x][tight] = answer;
} 

int main()  {
    string L, R;
    cin >> L >> R:
    int x;
    cin >> x;
    memset(dp, -1, sizeof(dp));

    cout << (solve(R, R.length(), x, 0)) << endl;
}
