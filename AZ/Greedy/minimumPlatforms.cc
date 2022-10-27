#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arrival(n), dept(n);
    for(auto &x: arrival) cin >> x;
    for(auto &x: dept) cin >> x;

    sort(arrival.begin(), arrival.end());
    sort(dept.begin(), dept.end());

    int i = 0, j = 0;
    int cnt = 0;

    while(i < n and j < n) {
        int cr = 0;
        while(i < n and arrival[i] <= dept[j]) {
            i++;
            cr++;
        } 
        j++;
        cnt = max(cr, cnt);
    }

    cout << cnt << endl;
    return 0;
}
