#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> cities;
    vector<int> rank;
public:
    
    int find(int city) {
        // return cities[city];
        // cout << city << " " << cities[city] << endl;
        if(city == cities[city]) return city;
        return cities[city] = find(cities[city]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int m = isConnected.size(); // number of cities
        int n = isConnected[0].size();
        cities.resize(m);
        rank.resize(m, 1);
        int size = m;
        // for(auto x: cities)cout<<x<<' ';
        // cout << "\n";
        // cout << cities.size() << "\n";
        
        for(int i=0; i<m; ++i){
            cities[i] = i;
        }
        // vector<int> rank(m, 1);
        /* Can I call lambda function recursively? */
        // auto find = [&](int city){
        //     if(city == cities[city]) return city;
        //     return cities[city] = find(city);
        // }
        
        auto _union = [&](int A, int B){
            int rootA = find(A);
            int rootB = find(B);
            
            // cout << rootA << " " << rootB << endl;
            if(rootA != rootB) {
                if(rank[rootA] > rank[rootB]) {
                    cities[rootB] = rootA;
                } else if(rank[A] < rank[rootB]) {
                    cities[rootA] = rootB;
                } else {
                    cities[rootA] = rootB;
                    rank[rootB] += 1;
                }
            }
            size -= 1;
        };
        
        
        for(int i=0; i<m; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(isConnected[i][j]) 
                {
                    if(find(i) != find(j))
                    {
                        // if two cities have different root node 
                        // => they are not connected
                        _union(i, j);
                    }
                }
            }
        }
        // for(auto x: rank)cout<<x<<' ';
        // cout << "\n";
        // set<int> s(cities.begin(), cities.end());
        // return s.size();
        return size;
    }
};

// [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]

int main(int argc, char *argv[])
{
    int m, n; cin >> m >> n;
    vector<vector<int>> isConnected(m, vector<int>(n));

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> isConnected[i][j];
        }
    }
    Solution sol;
    cout << "Number of Provinces : " <<  sol.findCircleNum(isConnected) << "\n";

    return 0;
}