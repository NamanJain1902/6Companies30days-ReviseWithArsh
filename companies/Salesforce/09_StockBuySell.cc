#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        //Function to find the days of buying and selling stock for max profit.
        vector<vector<int> > stockBuySell(vector<int> A, int n){
            // code here
            int b = 0, s = 0;
            vector<vector<int>> res;

            for(int curr = 0; curr < n; ++curr){

                if(A[curr] > A[b]){
                    if(A[curr] > A[s]){
                        s=curr;
                    }
                } else {
                    res.push_back({b, s});
                    b = curr;
                    s = curr;
                }
            }
            res.push_back({b, s});

            return res;
        }
        void stockBuySell(int price[], int n) {
            vector<vector<int>> ans;
            for (int i=1; i<n; i++){
                vector<int> temp;
                if (price[i] > price[i-1]){
                    temp.push_back(i-1);
                    while (i<n&&price[i] >= price[i-1]) i++;
                    temp.push_back(i-1);
                    ans.push_back(temp);
                }
            }
            if(ans.empty()){
                cout << "No Profit" << endl;
                return;
            }
            for (auto i:ans){
                cout << "("<< i[0] << " "<< i[1] << ") ";
            }
            cout << endl;
            return ;
        }
};

int main(){
    int n;cin>>n;vector<int> v(n);for(auto &x: v)cin>>x;
    Solution sol;
    vector<vector<int>> res = sol.stockBuySell(v, n);
    for(auto p : res){
        cout << p[0] << ' ' << p[1] << "\n";
    }
    return 0;
}
