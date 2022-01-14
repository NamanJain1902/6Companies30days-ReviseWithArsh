#include<bits/stdc++.h>
using namespace std;

int HMAX = (int)1e9 + 9;
int memo[100][100];

int rec(vector<int> &v, int idx, int sm, int tsm, int cnt){
    if(sm == tsm || sm == 0) cnt+=1;
    if(idx == v.size()) return cnt;
    cnt = 0;
    int yes = rec(v, idx+1, sm + v[idx], tsm, cnt);
    int no = rec(v, idx+1, sm, tsm, cnt);

    return yes + no;
}

int subsetSumSpaceOP(vector<int> &a, int n, int sum)
{
    int tab[2][sum + 1];
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] > j)
                tab[i%2][j] = tab[(i+1)%2][j];
            else
            {
                int val = ((j - a[i - 1]) <= sum ? j - a[i-1] : -1);
                if(val < 0){
                    tab[i%2][j] = tab[(i+1)%2][j];
                } else{
                    tab[i%2][j] = tab[(i+1)%2][j] + tab[(i+1)%2][val];
                }
            }
        }
    }

    for(int i=0;i<=1;++i){
        for(int j=0;j<=sum;j++){
            cout<<tab[i][j] << ' ';
        }
        cout<<endl;
    }
    return tab[n%2][sum] + tab[n%2][0];
}
int subsetSum(vector<int> &a, int n, int sum)
{
    int tab[n + 1][sum + 1];
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                int val = ((j - a[i - 1]) <= sum ? j - a[i-1] : -1);
                if(val < 0){
                    tab[i][j] = tab[i-1][j];
                } else{
                    tab[i][j] = tab[i - 1][j] + tab[i - 1][val];
                }
            }
        }
    }

    for(int i=0;i<=n;++i){
        for(int j=0;j<=sum;j++){
            cout<<tab[i][j] << ' ';
        }
        cout<<endl;
    }
    return tab[n][sum] + tab[n][0];
}
int main(){
    vector<int> v = {1, 2, -1, 4, 5};
    int tsm = 9;
    int cnt = 0;
    cout << rec(v, 0, 0, tsm, cnt) << endl;
    cout << subsetSumSpaceOP(v, v.size(), tsm) << endl;
    cout << isSubsetSum(v, v.size(), tsm) << endl;
}
/*
int distributeChocolatesAmongDrags(vector<int> &cards, vector<int> & queries) {
    int mod = (int)(1e9) + 9;
    int tar = accumulate(queries.begin(), queries.end(), 0);
    int n = cards.size();
    
    **
     * dp[i][j] stores count of subsets that forms the sum of j
     *
    vector<vector<int>> dp(n+1, vector<int>(tar+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=tar; ++j){
            if(dp[i-1][j] > 0){
                dp[i][j] = dp
            }
        }
    }

}

int a[] = {1, 2, 4, 5, 9};
int x = 9, n = 5;
int fun(int sum,int step)
{
   if(step==n) return sum==x;
   if(memo[sum][step]!=-1) return memo[sum][step];
   int ans=0;
   ans+=fun(sum,step+1);
   ans+=fun(sum+a[step],step+1);
   return memo[sum][step]=ans;
}
int main(){
    int ans = fun(0, 0);
    cout << ans << endl;
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; j++){
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
/*    vector<int> cards = {1, 2, -1, 4, 5};
    vector<int> queries = {9};
    int n = cards.size();
    int sm = accumulate(queries.begin(), queries.end(), 0);
    int ans = CountSubsetsWithGivenSum(cards, 0, sm, 0);
    cout << ans << endl;
memset(memo, -1, sizeof(memo));
    for(auto sum: queries){
        cout << memo[sum][n-1] << endl;
    }
//    cout << distributeChocolatesAmongDrags(cards, queries) << endl
*/

