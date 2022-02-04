#include<bits/stdc++.h>
using namespace std;


class UnionFind {
public:
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    /* log(n) or length of path between root 
       and node defined in root vector */
    int find(int x) {
        // cout << x <<" "<< root[x] << "\n";
        if(x == root[x]) return x;
        return find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            root[y] = rootX;
        }
    }

    bool connected(int x, int y) {
        // cout << "Checking for connection between " << x << " and " << y << "\n";
        return find(x) == find(y);
    }

    void print(){
        for(auto x: root)cout<<x<<' ';
        cout << "\n";
    }

private:
    vector<int> root;
};


int main(){
    cout << boolalpha; // for displaying boolean as string literals.

    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);

    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    
    // cout << uf.connected(1, 5) << endl;  // true
    // cout << uf.connected(5, 7) << endl;  // true
    // cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

    uf.print();
    return 0;
}