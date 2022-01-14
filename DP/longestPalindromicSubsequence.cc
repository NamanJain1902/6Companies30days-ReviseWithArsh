#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s){
        int low = 0;
        int high = s.length() - 1;
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            low++; high--;
        }
        return true;
    }
    int max(int a, int b){
        if(a >= b)  return a;
        return b;
    }
    void getSS(string s, string os, int &omax){
        if(s.length() == 0){
            if(isPalindrome(os)){
                omax = max(omax, os.length());
            }
            return;
        }
        getSS(s.substr(1), os + s[0], omax);
        getSS(s.substr(1), os, omax);
    }
    
    int longestPalindromeSubseq(string s) {
       int omax = 0;
       getSS(s, "", omax);
       return omax;
    }
};

int main()
{
    string s;cin>>s;
    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}
