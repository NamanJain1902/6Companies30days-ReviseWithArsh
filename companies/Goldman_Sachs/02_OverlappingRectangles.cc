
class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        
        // Attempt 1: Checking Overlapping Cases: WA
        // if((L1[0] < L2[0] || L1[0] < R2[0]) && (L2[0] < R1[0] || R2[0] < R1[0])){
        //     return true;
        // }
        // if((L1[1] < L2[1] || L1[1] < R2[1]) && (L2[1] < R1[1] || R2[1] < R1[1])){
        //     return true;
        // }
        
        // if((L2[0] < L1[0] || L2[0] < R1[0]) && (L1[0] < R2[0] || R1[0] < R2[0])){
        //     return true;
        // }
        // if((L2[1] < L1[1] || L2[1] < R1[1]) && (L1[1] < R2[1] || R1[1] < R2[1])){
        //     return true;
        // }
        
        // return false;
        /*
            Failed for input: -88 -99 79 -100 -51 -59 -10 -97
            
            Expected  Output: 0
            My Code Output  : 1
        */
        
        
        // Attempt 2: Checking Non-Overlapping Cases : AC
        if( (L2[0] > R1[0]) || (R2[0] < L1[0]) ||
            (L2[1] < R1[1]) || (R2[1] > L1[1])) return false;
        
        return true;
        
        // Attempt 3: Checking Overlapping Cases: AC
        return (R2[0] >= L1[0] and R2[1] <= L1[1]) and (L2[0] <= R1[0] and L2[1] >= R1[1]);
    }
};
