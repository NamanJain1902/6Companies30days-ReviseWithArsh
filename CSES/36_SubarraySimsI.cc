#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // int arr[n];
    queue<int> q;
    int sum = 0, cnt = 0;
    for(int i=0; i<n; ++i){
        // cin >> arr[i];
        int x;
        cin >> x;

        while(q.size() > 0 and (sum + x > m)) {
            sum -= q.front();
            q.pop();
        }
        
        if(sum + x <= m) {
            sum += x;
            if(sum == m) cnt++;
            q.push(x);
        }         
    }

    cout << cnt << endl;

}