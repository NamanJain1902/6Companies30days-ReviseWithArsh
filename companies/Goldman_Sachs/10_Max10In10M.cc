#include<bits/stdc++.h>
using namespace std;

// vector<int> max10In10M__TryingToReplicateSetFuntionality__notworking(vector<int> &v){
//     vector<int> res;
//     int n = v.size();
//     if(n <= 10) return v;

//     for(int i=0; i<n; ++i) {
//         if(res.size() == 10) {
//             break;
//         }
//         res.push_back(v[i]);
//     }

//     sort(res.begin(), res.end(), greater<int>());

//     for(int i=10; i < n; ++i){
//         int num = v[i];
//         vector<int>::iterator lb = lower_bound(res.begin(), res.end(), num);
//         cout << "lb: " << *lb << endl;

//         if(lb != res.end()){
//             res[res.size() - 1] = num;
//             sort(res.begin(), res.end(), greater<int>());
//         }
//     }

//     // vector<int> rs;
//     // for(auto x: res)rs.push_back(x);
//     return res;
// }


/*

set<int, greater<int>> keeps elements in descending order
Speciality:     
    s.upper_bound(x) will give next smallest element than x
    s.lower_bound(x) will give element <= x
*/

vector<int> max10In10M__AC(vector<int> &v){
    set<int, greater<int>> s;
    int n = v.size();

    if(n <= 10) return v;

    for(int i=0; i<n; ++i) {
        if(s.size() == 10) {
            break;
        }
        s.insert(v[i]);
    }
    // for(auto x: s)cout << x << ' ';
    // puts("");

    for(int i=10; i < n; ++i){
        int num = v[i];
        set<int>::iterator ub = s.upper_bound(num);
        auto it = s.end();
        it--;

        if(ub != s.end()){
            s.erase(it);
            s.insert(num);
        }
    }

    vector<int> res;
    for(auto x: s)res.push_back(x);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for(auto &x: v)cin>>x;

    vector<int> res = max10In10M__AC(v);

    for(auto x: res)cout<<x<<" ";
    cout << endl;
    return 0;
}
