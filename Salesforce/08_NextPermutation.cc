#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int ind = 0;
        vector<int> v = arr;
        for(int i = N-2;i >= 0;i--){
            if(v[i] < v[i+1]){
                ind = i;
                break;
            }
        }
        for(int i = N-1;i > ind;i--){
            if(v[i] > v[ind]){
                swap(v[i], v[ind]);
                ind++;
                break;
            }
        }
        for(int i = 0;i < (N-ind)/2;i++)
            swap(v[i+ind], v[N-i-1]);
        return v;
    }
};

vector<int> nextPermutation(const vector<int> &v){
    
    return  {};
}
int main()
{
    int n;cin>>n;vector<int> v(n);for(auto& x: v)cin>>x;
    Solution sol;
    vector<int> res = sol.nextPermutation(v.size(), v);for(auto x: res) cout<<x<<' ';
    puts("");return 0;
}
