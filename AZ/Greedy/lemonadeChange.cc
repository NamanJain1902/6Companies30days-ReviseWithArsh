/*
"Greedy" implies that there is some "locally optimal" action 
you can take which will (for the purposes of a working solution) 
guarantee you'll reach the desired solution if one is possible. 

In this case, we have a heuristic (i.e. always give out 
higher-denomination bills, in this case $10 bills rather 
than $5 bills) preferentially.

The fact that this works is not a given. While the intuition 
may be somewhat obvious in this case, it still qualifies as 
greedy, as we're choosing the locally-optimal option of always 
giving out $10 bills first (if possible) before giving out any 
$5 bills, which in this particular case gives the correct solution.
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coins[2]{0};
        bool ok = true;
        for(auto x: bills) {
            switch(x) {
                case 5:
                    coins[0]++;
                    break;
                case 10:
                    coins[1]++;
                    if(coins[0] == 0)
                        ok = false;
                    coins[0]--;
                    break;
                case 20:
                    if(coins[0] == 0 && coins[1] == 0){
                        ok = false;
                    } else if(coins[0] == 0) {
                        ok = false;
                    } else if(coins[1] == 0) {
                        if(coins[0] - 3 >= 0)
                            coins[0] -= 3;   
                        else 
                            ok = false;
                    } else {
                        coins[0]--;
                        coins[1]--;
                    }
                    break;
            }
            
            if(!ok) return false;
        }
        return true;
    }
};