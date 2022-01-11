#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) {
    static int narr[2];
    int A=0, B=0; 
    vector<int> v(n + 1, 0);

    for(int i=0; i<n; ++i) {
        v[arr[i]]++;
    }

    for(int i=1; i<=n; ++i){
        if(v[i] == 0)   A = i;
        if(v[i] > 1)    B = i;
        if(A != 0 and B != 0) break;
    }

    /**
     * Since it will destroy once the funtion scope end, we have used static keyword
    */
    narr[0] = B;
    narr[1] = A;
    
    return narr;
}

int main() {
    int n;cin>>n;int v[n];
    for(int i=0; i<n; ++i) cin >> v[i];

    auto ans = findTwoElement(v, n);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
