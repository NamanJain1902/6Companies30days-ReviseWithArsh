#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin >> n;
vector<int> v(n);
for(auto &x: v)cin>>x;
vector<int> dp(n, 1);
int omax=0;
for(int i=0; i<n; ++i){
    for(int j=0; j<i; ++j){
        if(v[i] > v[j]){
            if(dp[i] > dp[j]){
                dp[i] = dp[j];
            }
        }
    }
    dp[i]+=1;
    omax = max(dp[i], omax);
}
cout << omax << endl;
return 0;
}
