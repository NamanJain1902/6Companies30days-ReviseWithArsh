class Solution{   
    public:
        int getPairsCount(int arr[], int n, int k) {
            // code here
            // unordered_set<int> uset;
            unordered_map<int, int> hmap;

            int cnt = 0;
            for(int i=0; i<n; ++i){
                if(arr[i] > k){
                    continue;
                }

                int diff = k - arr[i];

                // if(uset.count(diff) > 0){
                //     cnt++;
                // }
                if(hmap.count(diff)){
                    cnt+=hmap[diff];
                }
                hmap[arr[i]]++;
                // uset.insert(arr[i]);
            }
            return cnt;

        }
};
