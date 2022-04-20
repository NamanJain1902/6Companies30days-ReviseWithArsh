class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int i,now,ans;
        now=target;
        ans=0;
        while (now>1)
        {
            if (maxDoubles==0)
            {
                ans+=now-1;
                break;
            }
            ans+=now%2;
            now/=2;
            ans++;
            maxDoubles--;
        }
        return ans;
    }
};

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int cnt = 0;
        
        for(int i=target; i>1;){
            
            if(maxDoubles == 0){
                cnt += (i-1);
                break;
            }
            if(i % 2 == 0 && maxDoubles){
                i /= 2;
                cnt++;
                maxDoubles--;
            } else{
                i--;
                cnt++;
            }             
        }
        return cnt;
    }
};