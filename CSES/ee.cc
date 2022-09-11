#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    map<int, int> m;
	    int x;
	    for(int i=0; i<n; ++i){
	        cin >> x;
	        m[x]++;
	    }
        vector<int> f;
	    for(auto x: m){
	        f.push_back(x.second);
	    }
        sort(f.begin(), f.end(), greater<int>());
        f[0] = f[0] / 2 + f[0] % 2;
        sort(f.begin(), f.end(), greater<int>());
        cout << f[0] << endl;
	}
	return 0;
}
