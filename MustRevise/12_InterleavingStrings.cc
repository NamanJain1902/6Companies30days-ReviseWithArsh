// 97 https://leetcode.com/problems/interleaving-string/
class Solution {
public:
    int dp[102][102];
    bool helper(string s1, string s2, string s3, int l1, int l2, int l3) {
        if(l1<0 && l2<0 && l3<0) return true;
        if(l1>=0 && l2>=0 && dp[l1][l2] != -1) return dp[l1][l2];

        if(l1>=0 && s1[l1] == s3[l3] && l2>=0 && s2[l2] == s3[l3]) {
        return dp[l1][l2] = (helper(s1, s2, s3, l1-1, l2, l3-1) || helper(s1, s2, s3, l1, l2-1, l3-1));
        } else if(l1 >= 0 && s1[l1] == s3[l3]){
        return helper(s1, s2, s3, l1-1, l2, l3-1);
        } else if(l2 >= 0 && s2[l2] == s3[l3]) {
        return helper(s1, s2, s3, l1, l2-1, l3-1);
        } else return false;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        memset(dp, -1, sizeof(dp));
        if((l1 + l2) != l3) return false;
        return helper(s1, s2, s3, l1-1, l2-1, l3-1);
    }
};
