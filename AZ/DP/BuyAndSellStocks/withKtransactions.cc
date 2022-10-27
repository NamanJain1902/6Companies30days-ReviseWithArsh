
// Memoization
class Solution {
public:
    enum stockState {
        INHAND = 1, 
        NOTHING = 0, 
        SOLD = 0, 
        BUY = 1
    };
    
    int buyOrSell(int k, vector<int> &prices, int day, stockState bought, 
                     vector<vector<vector<int>>> &vvv) {
        if(k <= 0 or day >= prices.size()) return 0;
        if(vvv[day][k][bought] != -1) return vvv[day][k][bought];
        int profit = 0;
        if(bought) {
            // either sell it today..grab the profit
            // or keep it and move on
            // collecting profit after selling the stock
            int sold = prices[day]  + buyOrSell(k-1, prices, day + 1, SOLD, vvv);
            int kept = buyOrSell(k, prices, day + 1, INHAND, vvv);
            profit = max({profit, sold, kept});
        } else {//now we can either buy prices[i] or we can skip it and try next to buy
            // buy today
            // it can be argued that not buying anything 
            // will be beneficial only when there's no other day
            // when price of stock is higher than price of
            // current day.
            int buy  = -prices[day] + buyOrSell(k, prices, day + 1, BUY, vvv);
            int pass = buyOrSell(k, prices, day + 1, NOTHING, vvv);
            profit = max({profit, buy, pass});
            // profit = max(profit, buy);
        }
        return vvv[day][k][bought] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> vvv(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));
      
        return buyOrSell(k, prices, 0, NOTHING, vvv);
    }




    // dp
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        vector<vector<vector<int>>> dp;
   
        dp.resize(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));

        // if k == 0 => no transaction allowed => 0 profit
            
        // for(int i=0; i<n; ++i) {
        //     dp[i][0][0] = dp[i][0][1] = 0;
        // }
        // for(int i=0; i<=k; ++i) {
        //     dp[n][i][0] = dp[n][i][1] = 0; 
        // }
            
        for(int day=n-1; day>=0; --day) {                
            
            for(int i=1; i<=k; ++i) {
                for(int bought=0; bought<=1; bought++) {  
                    
                    if(bought) {
                        int sold = prices[day] + dp[day+1][i-1][0];
                        int kept = dp[day+1][i][1];
                        dp[day][i][bought]  = max(sold, kept);
                    } else {
                        int buy = -prices[day] + dp[day+1][i][1];
                        int pass = dp[day+1][i][0];
                        dp[day][i][bought]  = max(buy, pass);
                    }
                    
                }
            }
           
            // ans = max(ans, profit);
        }
        
        return dp[0][k][0];
    }
};