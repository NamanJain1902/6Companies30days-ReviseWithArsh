/**
* @author NamanJain1902
* On: 30/01/2022 
* At: 08:33:09
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("avx,avx2")

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <numeric>
#include <climits>

#include <array>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
 
#include <cstring>
#include <ostream>
#include <type_traits>
#include <utility>
#include <chrono>
#include <random>
 
using namespace std;

#define pr pair<int, int>
#define pb push_back
#define s second
#define f first
#define ll long long
#define int long long int
#define sz(x) ((int)x.size())

const int MAX = 100000 + 5;
const int HMAX = 1000000007;

int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%HMAX;power >>= 1;}return ans;}
void readarr(int *arr, int n){for(int i=0; i<n; ++i){cin >> arr[i];}}
int binpower(int base, int power){int ans = 1;while(power>0){if(power%2)  ans = ans * base;base *= base;power /= 2;}return ans;}

class Solution0 {
public:
    int binaryExponentiation(int base, int power, int moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%moduloval;power >>= 1;}return ans;}
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        cout << s << endl;
        int n = s.length();
        for(int i=0 ;i<(n-k); i++){
            
            int val = 0;
            int e = 0;
            cout << val << endl;
            for(int j=i; j<(i+k); ++j){
                
                int num = (s[j] - 'a') + 1;
                int p = binaryExponentiation(power, e, modulo);
                e++;
                val += ((num * p) % modulo);
                cout << e << ' ' << num << ' ' << p << " " << val << endl;
            }
            val %= modulo;
            cout << val << endl;
            if(val == hashValue){
                return s.substr(i, k);
            }
        }
        return s;
    }
};

class Solution1 {
public:
    long long binaryExponentiation(long long base, long long power, long long moduloval){int ans = 1;while(power > 0){if(power % 2) ans = (ans * base) % moduloval;base = (base*base)%moduloval;power >>= 1;}return ans;}
    
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {    
        vector<long long> dp(k, 0);
        dp[0] = 1LL;
        
        for(int i=1; i<k; ++i){
            dp[i] = binaryExponentiation(power, i, modulo);
        }
        long long val = 0;
        for(int i=0; i<k; ++i){
            long long num = (s[i] - 'a') + 1;
            val += ((num % modulo) * (dp[i] % modulo) );
        }
        // val %= modulo;
        if(val % modulo == hashValue){
            return s.substr(0, k);
        }


        int n = s.length();
        for(int i=1; i<(n-k); ++i){
            long long num = (s[i-1] - 'a') + 1;
            // cout << val << endl;
            val -= num;

            // cout << val << endl;
            long long nnum = (s[i+k-1] - 'a') + 1;
            // cout << num <<" " << nnum << " " << dp[k-1] << endl;
            val += (nnum % modulo);
            // cout << val  << endl;

            // val %= modulo;
            if(val % modulo == hashValue){
                return s.substr(i, k);d
            }
        }

        return s;
    }
};


using LL = long long;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int i = s.size() - k, ans = -1;
        LL p = 1, h = 0;
        for (int j = 0; j < k; j += 1) {
            h = (h + p * (s[i + j] - 'a' + 1)) % modulo;
            p = p * power % modulo;
        }
        if (h == hashValue) ans = i;

        for (int j = i - 1; j >= 0; j -= 1) {
            h = (h * power + modulo - p * (s[j + k] - 'a' + 1) % modulo + s[j] - 'a' + 1) % modulo;
            if (h == hashValue) ans = j;
        }
        return s.substr(ans, k);
    }
};


class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n=s.size();
        vector<int>f(n+5);
        vector<int>pw(n+5);
        pw[0]=1;
        for (int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*power%mod;
        for (int i=n;i>=1;i--)
        {
        	f[i]=(1ll*f[i+1]*power+s[i-1]-'a'+1)%mod;
        }
        
        for (int i=1;i+k-1<=n;i++)
        {
        	int r=i+k-1,l=i;
        	// cout<<l<<" "<<r<<" "<<(1ll*f[l]-1ll*f[r+1]*pw[r-l+1]%mod+mod)%mod<<" "<<f[l]<<" "<<f[r+1]*pw[r-l+1]<<endl;
        	if ((1ll*f[l]-1ll*f[r+1]*pw[r-l+1]%mod+mod)%mod==hashValue) 
        	{
        		string res="";
        		for (int j=i;j<=i+k-1;j++)
        			res+=s[j-1];
        		return res;
        	}
        }
        return "";
    }
};

// 	JOHNKRAM code252
class Solution {
    typedef long long ll;
    int h[20005],p[20005];
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n=s.size(),i,j;
        for(i=p[0]=1;i<=n;i++)p[i]=(ll)p[i-1]*power%modulo;
        for(h[n]=0,i=n-1;~i;i--)h[i]=((ll)h[i+1]*power+(s[i]^96))%modulo;
        for(i=0;;i++)if(h[i]==(hashValue+(ll)h[i+k]*p[k])%modulo)break;
        string ans;
        for(j=0;j<k;j++)ans+=s[i+j];
        return ans;
    }
};


// 	micromaker  code
class Solution {
public:
    long long val(char x){return (long long)(x-'a'+1);}
    long long base,mod;
    string S;
    long long f[100050],pw[100050];

    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        S=s,base=power,mod=modulo;
        int n=(int)s.size();
        
        for(int i=0;i <= n+5;++i)
            f[i] = pw[i] =0;
        

        // powers
        pw[0]=1;
        for(int i=1;i <= n;++i)
            pw[i] = pw[i-1] * base % mod;
        
        f[n+1]=0;
        for(int i=n; i; --i)
            f[i] = (f[i+1] * base + val(s[i-1] ))%mod;
        
        for(int i=1; i+k-1<=n;++i)
        {
            int j=i+k-1;
            if((f[i] - f[j+1] * pw[j-i+1] % mod + mod) % mod == hashValue)
            {
                string t = s.substr(i-1,k);
                return t;
            }
        }
        
        return "-1";
    }
};

void solve(){
    string s;
    cin >> s;
    int power, mod, k, hashVal;
    cin >> power >> mod >> k >> hashVal;

    Solution sol;
    cout << sol.subStrHash(s, power, mod, k, hashVal) << endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
//   int t;
//   cin >> t;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
