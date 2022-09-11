#include<bits/stdc++.h>
using namespace std;


struct Pair{
    int val;
    int steps;
    Pair(){}
    Pair(int val, int steps){
        this->val = val;
        this->steps = steps;
    }
};


int main() {

    // int n; cin >> n;
    // vector<int> arr(n);
    // for(auto &x: arr) cin >> x;

    int arr[] = {2, 5, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int start = 2;
    int end = 100;

    int visited[end+1]{0};
    queue<Pair> q;
    q.emplace(start, 0);
    
    int ans;
    
    while (!q.empty()) 
    {
        /* code */
        int node = q.front().val;
        int step = q.front().steps;
        q.pop();

        if(node == end) {
            ans = step;
            break;
        }

        for(int i=0; i<n; ++i) {
            int dest = node * arr[i];

            if(dest <= end and !visited[dest]){
                q.emplace(dest, step + 1);
                visited[dest] = 1;
            }
        }
    }

    cout << ans << endl;   

    return 0;
}