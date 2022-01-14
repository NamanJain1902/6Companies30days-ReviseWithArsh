#include<bits/stdc++.h>
using namespace std;

struct Box{
    int idx, ojumps, tjumps;
    string psf;

    Box(){}
    Box(int idx, int ojumps, int tjumps, string psf){
        this->idx = idx;
        this->ojumps = ojumps;
        this->tjumps = tjumps;
        this->psf = psf;
    }
};

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(auto &x: v)cin>>x;

    vector<int> dp(n, 1000);
    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--){
        for(int j=1; j<=v[i] && (i+j) < n; ++j){
            dp[i] = min(dp[i], dp[i+j] + 1);
        }
    }
    

    cout << dp[0] << endl;

    // for(auto x: dp)cout<< x  << " ";
    string path;
 
    queue<Box> q;
    q.emplace(0, v[0], dp[0], "0");

    while(!q.empty()){
        Box curr = q.front();
        q.pop();

        int start = curr.idx;
        int ntar = dp[start] - 1;
        int max_jump = curr.ojumps;

        // cout << "start: " << start << "\t ojumps: " << max_jump << "\t ntar: " << ntar << endl;


        if(start == n-1){
            curr.psf += " .";
            
        // cout << start  << endl;
            cout << curr.psf << endl;
        }
        
        for(int j=1; j<=max_jump && (start+j) < n; ++j){
            if(dp[start+j] == ntar){
                q.emplace(start+j, v[start+j], dp[start+j], curr.psf + " -> " + to_string(start+j));
            }    
        }        
    }
        
}

