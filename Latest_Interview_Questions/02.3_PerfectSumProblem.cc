#include<bits/stdc++.h>
using namespace std;

/**
 *   print all subsets of the given array with sum
 *   equal to a given sum.
*/

void bfs(vector<int> &v, int idx, int sm, vector<int> &path){
    if(idx == 0 and sm != 0 and dp[0][sm]){
        path.push_back(v[idx]);

        if(v[i] == sm){
            for(auto x: path) cout << x <<' ' ;
            cout << "\n";
        }
        return;
    }

    if(i == 0 and sm == 0){
        for(auto x: path)cout<<x << ' ';cout<<"\n";
        return;
    }

    if(dp[])
}

int main()
{
    int n;cin>>n;vector<int> v(n);
    for(auto &x: v)cin>>x;
}
