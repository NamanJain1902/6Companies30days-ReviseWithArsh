class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        if(n < 3) return 0;
        vector<int> pa(n, 1), qa(n, 1);
        
        for(int i=1; i<n; ++i){
            if(arr[i] > arr[i-1]){
                pa[i] += (pa[i-1] + 1);
            }
            if(arr[n-i-1] > arr[n-i]) {
                qa[n-i-1] += (qa[n-i]+1);
            }
        }
        
        int omax = 0;
        for(int i=0; i<n; ++i){
            if(pa[i] != 1 and qa[i] != 1)
                omax = max(omax, qa[i] + pa[i] - 1);
        }
        
        return (omax == 1 ? 0 : omax);
    }
};
