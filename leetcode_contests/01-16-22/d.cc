class Solution {
public:
    long long maxRunTime(int n, vector<int>& a) {
        int i,now;
        long long tot;
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        tot=0;
        for (i=0;i<a.size();i++)
            tot+=a[i];
        now=n;
        for (i=0;i<a.size();i++)
        {
            if (a[i]<=tot/now)
            {
                return tot/now;
            }
            tot-=a[i];
            now--;
        }
        return 0;
    }
};

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int len = batteries.size();
        long  long  int  sm = 0;
        long long cnt = 0;
        for(int i=0; i<len; ++i){
            long long val = batteries[i];
            cnt += (val / n);
            sm += (val % n);
            
            cnt += (sm / n);
            sm -= (sm / n > 0 ? n + sm % n : 0);
        }
        
        return cnt;
    }
};