#include<bits/stdc++.h>
using namespace std;

int main() {
    int p, q, r;
    cin >> p >> q >> r;

    set<int> a, b, c;
    int mx = 0;

    for(int i=0; i<p; ++i) {
        int x;
        cin >> x;
        mx=max(mx, x);
        a.insert(x);
    }
    for(int i=0; i<q; ++i) {
        int x;
        cin >> x;
        mx=max(mx, x);
        b.insert(x);
    }
    for(int i=0; i<r; ++i) {
        int x;
        cin >> x;
        mx=max(mx, x);
        c.insert(x);
    }
    // for(auto &x: a) cin >> x, mx = max(mx, x);
    // for(auto &x: b) cin >> x, mx = max(mx, x);
    // for(auto &x: c) cin >> x, mx = max(mx, x);

    vector<int> t(mx+1);
    vector<int> ret;

    for(auto x: a) {
        t[x]++;
    }
    for(auto x: b) {
        t[x]++;
    }

    for(auto x: c) {
        t[x]++;
    }

    for(int i=0; i<t.size(); ++i) {
        if(t[i] >= 2) ret.push_back(i);
    }
    for(auto x: ret) {
        cout << x << " ";
    }
    cout << endl;
}