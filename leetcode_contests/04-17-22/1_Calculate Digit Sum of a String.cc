class Solution {
public:
    string digitSum(string s, int k) {
        int sl = s.length();
        string ret;
        while(sl > k){
            ret = "";
            for(int i = 0; i<sl;) {
                int num = 0;
                for(int j=1; j<=k; ++j, i++){
                    if(i == sl){
                        break;
                    }
                    num += (s[i] - '0');
                    
                }
                ret += to_string(num);
            }
            
            s = ret;
            sl = s.length();
        }
        
        return s;
    }
};