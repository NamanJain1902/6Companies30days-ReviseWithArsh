

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition1(int N , int M , int K) { 
        if(N==1)    return 1;
        
        M = M % N;
        int ans = M + K - 1;
        ans = ans > N ? ans - N : ans;
        
        return ans;
    }
   int findPosition(int N , int M , int K) {
        // code here
        int ans = (K + M - 1) % N;
        return ans == 0 ? N: ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
