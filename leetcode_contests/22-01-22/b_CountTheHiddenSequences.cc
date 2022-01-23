class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long sum  = 0;
        long long l=sum, h=sum;
        
        for(int i=0; i<(int)differences.size(); ++i){
            sum += differences[i];
            l = min(sum, l);
            h = max(sum, h);
        }
        long long ub = upper - h;
        long long lb = lower - l;
        return (ub-lb+1) > 0 ? ub-lb+1: 0;
    }
};