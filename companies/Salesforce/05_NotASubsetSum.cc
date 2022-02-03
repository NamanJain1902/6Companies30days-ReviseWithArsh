class Solution{   
    public:
        long long findSmallest(long long arr[], int n) {
            
            long long c=1;
            for(int i=0;i<n;i++)
                if(arr[i]<=c) { c+=arr[i]; }

            return c;
        }
};
