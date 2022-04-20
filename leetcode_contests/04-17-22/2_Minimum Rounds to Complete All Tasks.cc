class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(auto x: tasks){
            m[x]++;
        }
        
        int cnt = 0;
        for(auto [a, b]: m){
            cout << a << " -> " << b << endl;
            if(b % 3 == 0) {
                cnt += (b / 3);
            } else if(b == 1){
                return -1;
            } else {
                // b+=1;
                cnt += (b / 3) + 1;
            }
        }
        
        return cnt;
           
    }
};