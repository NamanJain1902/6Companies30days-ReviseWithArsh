#include<bits/stdc++.h>
using namespace std;


const int mod = 1e9+7;
// fermet's th.
int modularBinaryExponentiation(int base, int exponent) {
    if(exponent == 0) return 1;

    long long result = modularBinaryExponentiation(base, exponent/2);

    if(exponent & 1) 
        return (((result * result) % mod) * base) % mod;
    else
        return (result * result) % mod;
}

long ncr(int n, int r) {
    long ans = 1;
    for(int i = 0; i < r; i++) {
        ans *= n-i;
        ans /= i+1;
    }
    return ans % mod;
}
int numTrees(int n) {
    return ncr(2*n, n) / (n + 1);
}
int numTrees_WA(int n) {
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) 
        for(int j = 1; j <= i; j++)
            dp[i] += (dp[j-1] * dp[i-j]) % mod;
    return dp[n] % mod;
}
const int HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){
    int ans = 1;
    while(power > 0) {
        if(power % 2) 
            ans = (ans * base) % moduloval;

        base = (base*base)%HMAX;
        power >>= 1;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;

    if(n&1) {
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
//    cout << numTrees(n) << endl;
//    return 0;
    long long int ans = 1;
    for(int i=1; i<=n; ++i) {
        ans = ((((4*i - 2) * binaryExponentiation(i+1, mod-2, mod)) % mod)  * ans) % mod;
    }
    cout << ans << endl;
    return 0;
}
