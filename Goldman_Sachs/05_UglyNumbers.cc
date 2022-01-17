class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
    /*
        Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
        The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first
        11 ugly numbers. By convention, 1 is included. Write a program to 
        find Nth Ugly Number.
    */    
	ull getNthUglyNo(int n) {
	
	    ull p2 = 1, p3 = 1, p5 = 1;
	    
	    vector<ull> dp(n+1);
	    dp[1] = 1;
	    
	    for(ull i=2; i<=n; ++i) {
	        ull f2 = 2 * dp[p2];
	        ull f3 = 3 * dp[p3];
	        ull f5 = 5 * dp[p5];
	        
	        ull mini = min(f2, min(f3, f5));
	        
	        if(mini == f2){
	            p2++;
	        }
	        if(mini == f3){
	            p3++;
	        }
	        if(mini == f5){
	            p5++;
	        }
	        
	        dp[i] = mini;
	    }
	    
	    return dp[n];
	}
};
