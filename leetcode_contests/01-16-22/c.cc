long long d[110000];

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int i,j,n,tmp;
        memset(d,0,sizeof(d));
        n=questions.size();
        d[0]=0;
        for (i=0;i<n;i++)
        {
            if (d[i]>d[i+1]) d[i+1]=d[i];
            tmp=i+questions[i][1]+1;
            if (tmp>n) tmp=n;
            if (d[i]+questions[i][0]>d[tmp])
                d[tmp]=d[i]+questions[i][0];
        }
        return d[n];
    }
};

#define ll long long

class Solution {
public:
	int n;
	vector <ll> a, b, dp;

	ll f(int i) {
		if(i >= n) return 0;

		ll &ans = dp[i];
		if(ans != -1) return ans;
		return ans = max(f(i + 1), a[i] + f(i + b[i] + 1));
	}

	long long mostPoints(vector<vector<int>>& questions) {
		for(auto &v: questions) a.push_back(v[0]), b.push_back(v[1]);
		n = a.size();
		dp.resize(n, -1);

		ll ans = 0;
		for(int i = 0; i < n; i++) ans = max(ans, f(i));
		return ans;
	}
};



class Solution {
public:
    long long omax = INT_MIN;
    void brute(vector<vector<int>> &questions, int idx, long long sum, int &k){
        
        
        if(idx == questions.size()){
            omax = max(omax, sum);
            return;
        }
        
        
        brute(questions, idx + 1, sum, k - 1);
        
        if(k == 0)
        brute(questions, idx + 1, sum + questions[idx][0], questions[idx][1]);
    }    
    long long mostPoints(vector<vector<int>>& questions) {
        
        
        brute(questions, 0, 0, 0);
        
        return omax;
    }
};
