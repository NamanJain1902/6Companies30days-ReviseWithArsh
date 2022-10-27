#include<bits/stdc++.h>
using namespace std;


int fastenalFreebies(int input1, int input2, int input3[]) {

    vector<int> v;
    v.push_back(0);
    for(int i=0; i<input1; i++){
        v.push_back(input3[i]);
    }
    v.push_back(input2);
    
    int low = 1;  // input3[0];
    int high = 0;
   
    high = input2;
    
    while(low < high) {
        int mid = (low + high) >> 1;
        int cnt = 0;
        // cout << mid << endl;
        for(int i=1; i<input1; i++) {
            int x = v[i+1] - v[i];
            
            if(x < mid) cnt+=x;
            else cnt += mid;// (x / mid + (x % mid != 0));
        }
        cnt+=mid;
        // cout << cnt << endl;
        if(cnt <= input2) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n, f;
    cin >> n >> f;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];

    cout << fastenalFreebies(n, f, a) << endl;
}