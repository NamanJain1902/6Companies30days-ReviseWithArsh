#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int k;
    cin >> k;

    for(int i=0; i<k; ++i) {
        int start, end, value;
        cin >> start >> end >> value;

        v[start] += value;
        if(end + 1 < n)
            v[end+1] -= value;
    }

    for(int i=0; i<n; ++i) {
        v[i] += v[i-1];
    }

    for(auto &x: v) cout << x << ' ';
    puts("");
    return 0;
}
