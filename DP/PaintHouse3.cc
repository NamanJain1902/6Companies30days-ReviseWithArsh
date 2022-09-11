


/* MEMOIZATION */
class Solution {
    /*
       Complexity Analysis

       Here, MM is the number of houses, NN is the number of colors and TT is the number of target neighborhoods.

       Time complexity: O(M \cdot T \cdot N^2)O(M⋅T⋅N 
       2
       )

       Each state is defined by the values currIndex, neighborhoodCount, and prevHouseColor. Hence, there will be M \cdot T \cdot NM⋅T⋅N possible states, and in the worst-case scenario, we must visit most of the states to solve the original problem. Each recursive call requires O(N)O(N) time as we might need to iterate over all the colors. Thus, the total time complexity is equal to O(M \cdot T \cdot N^2)O(M⋅T⋅N 
       2
       ).

       Space complexity: O(M \cdot T \cdot N)O(M⋅T⋅N)

       The memoization results are stored in the table memo with size M \cdot T \cdot NM⋅T⋅N. Also, stack space in the recursion is equal to the maximum number of active functions. The maximum number of active functions will be at most MM i.e., one function call for every house. Hence, the space complexity is O(M \cdot T \cdot N)O(M⋅T⋅N).
     */
    public:
        int memo[100][100][21];        
        const int MAX_COST = 1e6+1;

        int rec(vector<int>& houses, vector<vector<int>>& cost, int idx, const int target, int neighborhoodCount, int prevHouseColor) {

            if(idx == houses.size()) {
                // if all the houses are traversed, check if the neighbor count is as expected or not
                return neighborhoodCount == target ? 0: MAX_COST;
            }  

            if(neighborhoodCount > target) {
                // if the neighborhoodCount are more that the threshold, we can't have target neighborhoods
                return MAX_COST;
            }

            if(memo[idx][neighborhoodCount][prevHouseColor] != -1) {
                return memo[idx][neighborhoodCount][prevHouseColor];
            }

            int min_cost = MAX_COST;

            // if the house is already painted, update the values accordingly
            if(houses[idx]) {
                int newNeighborhoodCount = neighborhoodCount + (houses[idx] != prevHouseColor);
                min_cost = rec(houses, cost, idx+1, target, newNeighborhoodCount, houses[idx]);
            } else {
                int totalColors = cost[0].size();

                for(int color = 1; color <= totalColors; ++color) {
                    int newNeighborhoodCount = neighborhoodCount + (color != prevHouseColor);
                    int curCost = cost[idx][color-1] + rec(houses, cost, idx+1, target, newNeighborhoodCount, color);
                    min_cost = min(min_cost, curCost);
                }
            }

            return  memo[idx][neighborhoodCount][prevHouseColor] = min_cost;
        }

        int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            memset(memo, -1, sizeof(memo));
            int min_cost = rec(houses, cost, 0, target, 0, 0);
            return (min_cost == MAX_COST ? -1: min_cost);
        }
};


/* RECURSION */
class Solution {
    public:
        void rec(vector<int>& houses, vector<vector<int>>& cost, int idx, int curcost, const int target, int &min_cost) {

            if(idx == houses.size()) {
                int g = 1;
                for(int i=1; i<houses.size(); ++i) {
                    if(houses[i] != houses[i-1]) {
                        g++;
                    }
                }
                if(g == target) min_cost = min(min_cost, curcost);
                return;
            }        
            for(int ci = 1; ci <= cost[0].size(); ++ci) {
                int nidx = idx;
                while(nidx < houses.size() and houses[nidx] != 0) nidx++;
                if(nidx < houses.size()){
                    houses[nidx] = ci;
                    curcost += cost[nidx][ci-1];
                }
                rec(houses, cost, nidx, curcost, target, min_cost);
                if(nidx < houses.size()){
                    houses[nidx] = 0;
                    curcost -= cost[nidx][ci-1];
                }
            }
        }

        int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            int min_cost = INT_MAX;
            rec(houses, cost, 0, 0, target, min_cost);
            return (min_cost == INT_MAX ? -1: min_cost);
        }
};
