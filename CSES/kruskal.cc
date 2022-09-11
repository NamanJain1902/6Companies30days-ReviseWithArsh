#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    /* After finding the root node, we can update the parent node of all 
    traversed elements to their root node. When we search for the root node 
    of the same element again, we only need to traverse two elements to find 
    its root node */
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionn(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    int n, m;
	cin >> n >> m;
    UnionFind obj(n+1);
	vector<vector<int>> graph;
	bool isConnected = false;
	for(int i=1; i<=m ;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph.push_back({a, b, c});
	}
	// sort edges according to min weights
	sort(graph.begin(), graph.end(), [&](vector<int> a, vector<int> b) {
		return a[2] < b[2];
	});
	int mincost = 0;

	for(int i=0; i<m; ++i) {
		int u = graph[i][0];
		int v = graph[i][1];
		int wt =  graph[i][2];

		if(obj.find(u) != obj.find(v)) {
			mincost += wt;
			obj.unionn(u, v);
		}
	}
	cout << mincost << endl;
    return 0;
}

