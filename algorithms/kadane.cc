#include<bits/stdc++.h>
using namespace std;

/*
input

5
2 -4 5 1 -2
*/
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x: v) cin >> x;


    vector<int> dp(n);
    dp[0] = v[0];
    int sum = v[0]; // current sum
    int overall_sum = v[0];
    for(int i=1; i<n; ++i) {
        // v[i] decides whether  join previous group or not
        if(sum >= 0) {
            sum += v[i];
        } else {
            sum = v[i];
        }

        dp[i] = sum;
        overall_sum = max(overall_sum, sum);
    }

    cout << "Sum: "  << sum << "\tOverall sum: " << overall_sum << endl;
    for(auto x: dp) {
        cout << x << ' ';
    }
    puts("");

    return 0;
}