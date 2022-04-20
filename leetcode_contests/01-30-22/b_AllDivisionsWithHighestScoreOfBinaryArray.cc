// froggygua code63
class Solution_froggygua   {
public:
	#define N 100010
	int n,a[N],pre[N],suf[N];
    vector<int> maxScoreIndices(vector<int> &nums) {
        n=nums.size();
        for(int i=1;i<=n;++i)a[i]=nums[i-1];
        for(int i=1;i<=n;++i)pre[i]=pre[i-1]+(a[i]==0);
        for(int i=n;i>=1;--i)suf[i]=suf[i+1]+(a[i]==1);
        int ans=0;
        for(int i=0;i<=n;++i)ans=max(ans,pre[i]+suf[i+1]);
        vector<int> jb;
        for(int i=0;i<=n;++i){
        	if(pre[i]+suf[i+1]==ans)jb.push_back(i);
        }
        return jb;
    }
};

// 	JOHNKRAM code252
class Solution_JOHNKRAM {
    int s[100005][2];
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size(),i,ans=0;
        for(i=0;i<n;i++)
        {
            copy(s[i],s[i]+2,s[i+1]);
            s[i+1][nums[i]]++;
        }
        for(i=0;i<=n;i++)ans=max(ans,s[i][0]+s[n][1]-s[i][1]);
        vector<int> a;
        for(i=0;i<=n;i++)if(s[i][0]+s[n][1]-s[i][1]==ans)a.push_back(i);
        return a;
    }
};

// xiaowuc1 code181
class Solution_xiaowuc1 {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = sz(nums);
        vector<int> lhs(n+1);
        for(int i = 0; i < n; i++) {
          lhs[i+1] = lhs[i] + (nums[i] == 0);
        }
        vector<int> rhs(n+1);
        for(int i = n-1; i >= 0; i--) {
          rhs[i] = rhs[i+1] + (nums[i] == 1);
        }
        int maxv = 0;
        for(int i = 0; i <= n; i++) 
            maxv = max(maxv, lhs[i] + rhs[i]);
        vector<int> ret;
        for(int i = 0; i <= n; i++) if(lhs[i] + rhs[i] == maxv) ret.pb(i);
        return ret;
    }
};

// my code
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n+1, 0), suf(n+1, 0);

        for(int i=0; i<=n; ++i) {
            pre[i+1] = (nums[i] == 0 ) + pre[i];
        }

        for(int i=n-1; i>=0; i--) {
            suf[i] = nums[i] + suf[i+1];
        }
        int mx = -1;
        for(int i=0; i<n; ++i){
            mx=max(mx, pre[i]+suf[i]);
        }
        vector<int> ret;
        for(int i=0; i<n; ++i){
            if(pre[i]+suf[i]==mx)ret.push_back(i);
        }
        return ret;
    };
};


// class Solution {
// public:
    
//     int omax = 0;
//     vector<int> dpz, dpo;
//     vector<pair<int,int>> rec(vector<int> &nums, int idx){
        
//         if(idx == nums.size()) {
            
//             int wt = accumulate
//         }
        
//         dpz[idx] += (nums[idx] == 0 ? (idx == 0) ? 1 : dpz[idx-1]+1 : (idx == 0) ? 0 : dpz[idx-1]);
        
//         vector<pair<int, int>> ltp = rec(nums, idx + 1);
        
//         // dpo[idx] += (nums[idx] == 1 ? (idx == 0) ? 1 : dpz[idx-1]+1 : (idx == 0) ? 0 : dpz[idx-1]);
//         int wt = 0;
        
        
//     }
    
//     vector<int> maxScoreIndices(vector<int>& nums) {
        
//         dp.resize(nums.size());
//         dp.fill(0);
//         int nones = accumulate(nums.begin(), nums.end(), 0);
        
        
//     }
// };