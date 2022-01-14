#include<bits/stdc++.h>
using  namespace std;

void print(string s ,vector<int> &v){
    cout << s << ":\t";
    for(auto x: v) cout  << x << ' ';
    cout << endl;
}
int main(){

    int n;cin >> n;
    vector<int> v(n,0);
    for(auto &x: v)cin>>x;
    int k;cin>>k;

    vector<int> prefixSum(n, 0), maxPrefixSum(n, 0), maxSuffixSum(n, 0);

    int sm = 0;
    for(int i=0; i<n; ++i) {
        if(i == 0){
            prefixSum[i] = v[i];
            sm += v[i];
            maxPrefixSum[i] = sm;
        } 
        else {
            if(i < k) {
                sm += v[i];
                maxPrefixSum[i] = sm;
            } else{
                sm += (v[i] - v[i-k]);
                maxPrefixSum[i] = max(maxPrefixSum[i-1], sm);   
            }
            prefixSum[i] = prefixSum[i-1] + v[i];
        }
    }

    sm=0;
    for(int i=n-1;i>=0;--i){
        if(i+k>=n){
            sm+=v[i];
            maxSuffixSum[i] = sm;
        }else{
            sm = sm + v[i] - v[i+k];
            maxSuffixSum[i] = max(sm, maxSuffixSum[i+1]);
        }
    }

    int smax=0;
    int spmsa = -1;
    int lsum = 0;
    int rsum = 0;

    for(int i=k;i<=2*k;++i){
        if((maxPrefixSum[i-1] + maxSuffixSum[i+k] + (prefixSum[i+k-1] - prefixSum[i-1])) > smax){
            smax = maxPrefixSum[i-1] + maxSuffixSum[i+k] + (prefixSum[i+k-1] - prefixSum[i-1]);
            lsum = maxPrefixSum[i-1];
            rsum = maxSuffixSum[i+k];
            spmsa = i;
        }
    }

    cout << smax << " ";

    for(int i=k-1; i<spmsa; i++){
        if(prefixSum[i] - (i - k < 0 ? 0 : prefixSum[i-k]) == lsum){
            cout << (i - k + 1 ) << " ";
            break;
        }
    }
    
    cout << spmsa << " ";

    for(int i=spmsa + (2 * k) - 1; i<n;  i++) {
        if(prefixSum[i] - prefixSum[i-k] == rsum) {
            cout << (i - k + 1) << " ";
            break;
        }
    }

    cout << endl;
}
