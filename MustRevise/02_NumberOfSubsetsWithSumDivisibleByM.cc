#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int brute(vector<int> &v, int m) {

        }
};

int main(){
    //    int n;cin>>n;vector<int> v;for(auto &x: v)cin>>x;int m;cin>>m;
    /*
       Subsequence of given set are
       {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3} and {1, 2, 3}. 
       And their sums are 1, 2, 3, 3, 5, 4 and 6.
    */
    vector<int> v = {1, 2, 3}; int m = 3; // output: 3
    Solution sol;
    cout << sol.brute(v, m) << endl;

    return 0;
}
