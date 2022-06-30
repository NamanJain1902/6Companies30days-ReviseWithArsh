class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int old_bought_state_price = -prices[0];
        int old_sell_state_price   = 0;
        int old_cool_state_price   = 0;

        int n = prices.size();

        for(int i=1; i<n; ++i) {
            int new_bought_state_price = 0;
            int new_sell_state_price   = 0;
            int new_cool_state_price   = 0;

            
            if(old_cool_state_price - prices[i] > old_bought_state_price) {
                new_bought_state_price = old_cool_state_price - prices[i];
            } else {
                new_bought_state_price = old_bought_state_price;
            }

            if(old_bought_state_price + prices[i] > old_sell_state_price) {
                new_sell_state_price = old_bought_state_price + prices[i];
            } else {
                new_sell_state_price = old_sell_state_price;
            }

            if(old_sell_state_price > old_cool_state_price) {
                new_cool_state_price =  old_sell_state_price;
            } else {
                new_cool_state_price = old_cool_state_price;
            }

            old_bought_state_price = new_bought_state_price;
            old_sell_state_price   = new_sell_state_price;
            old_cool_state_price   = new_cool_state_price;
        }

        return old_sell_state_price;
    }
};