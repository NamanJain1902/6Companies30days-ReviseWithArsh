class Solution{
public:
      int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        int dp[n]{0}, ispalindrome[n][n];
        
        for(int g=0; g<n;++g){
            for(int i=0, j=g; j<n;++j,++i) {
                if(g==0){
                    ispalindrome[i][j] = 1;
                } else if(g==1){
                    ispalindrome[i][j] = (str[i] == str[j]);
                } else {
                    ispalindrome[i][j] = (str[i] == str[j]) ? (ispalindrome[i+1][j-1]) : 0;
                }
            }
        }
    
        
        for(int i=1; i<n; ++i) {
            if(ispalindrome[0][i]){
                dp[i] = 0;
            } else{
                int mini = INT_MAX;
                for(int j=i; j>=1; j--) {
                    if(ispalindrome[j][i]) {
                        mini = min(mini, dp[j-1]);
                    }
                }
                dp[i] = mini + 1;
            }
        }
        
        return dp[n-1];
    }

    int palindromicPartition1(string str)
    {
        // code here
        int n = str.length();
        int dp[n][n], ispalindrome[n][n];
        
        for(int g=0; g<n;++g){
            for(int i=0, j=g; j<n;++j,++i) {
                if(g==0){
                    ispalindrome[i][j] = 1;
                } else if(g==1){
                    ispalindrome[i][j] = (str[i] == str[j]);
                } else {
                    ispalindrome[i][j] = (str[i] == str[j]) ? (ispalindrome[i+1][j-1]) : 0;
                }
            }
        }
        
        memset(dp, 0, sizeof(dp));
        
        for(int g=0; g<n; ++g) {
            for(int i=0, j=g; j<n; ++j, ++i) {
                if(g==0){
                    dp[i][j] = 0;
                } else if(g==1) {
                    dp[i][j] = (str[i] == str[j] ? 0 : 1);
                } else {
                    if(ispalindrome[i][j]) dp[i][j] = 0;
                    else {
                        int mini = INT_MAX;
                        for(int k=i; k<j; ++k) {
                            mini = min(dp[i][k]+dp[k+1][j], mini);
                        }
                        dp[i][j] = mini + 1;
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
