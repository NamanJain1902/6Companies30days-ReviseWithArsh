#include<bits/stdc++.h>
using namespace std;


struct Route{
    // int src;
    int dest;
}

vector<vector<Route>> flights;

int main() {
    int n, m;
    cin >> n >> m;

    // flight route information stored as adjacency list.
    flights.resize(n+1);
    for(int i=0; i<m; ++i) {
        int src, dest;
        flights[src].push_back(dest);
    }

    

}