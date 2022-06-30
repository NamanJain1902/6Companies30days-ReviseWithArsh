class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        
        int min_buy_idx   = 0; // keeping index value of minimum buying value or stock value observed so far in traversal of prices.
        int sell_idx  = 0; // current index
        int profit    = 0;
        int maxprofit = 0;
        
        while(sell_idx < n) {
            if(prices[min_buy_idx] > prices[sell_idx]) {
                min_buy_idx = sell_idx;
            }
            profit = prices[sell_idx] - prices[min_buy_idx];
            maxprofit = max(profit, maxprofit);
            sell_idx++;
        }
        
        return maxprofit;
        
    }
};