#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using kruskal's algo t find minimum-spanning-tree
vector<int> parent;
vector<int> ranka;

bool find(int node) {
	if(node == parent[node]) return node;
	return parent[node] = find(parent[node]);
}

void unionn(int a, int b){
	int pa = find(a);
	int pb = find(b);

	if(pa == pb) return;

	if(ranka[pa] > ranka[pb]){
		parent[pb] = pa;
	} else if(ranka[pb] < ranka[pa]) {
		parent[pa] = pb;
	} else {
		parent[pb] = pa;
		ranka[pa]++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
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
	parent.resize(n+1);
	ranka.resize(n+1, 1);
	iota(parent.begin(), parent.end(), 1);
	int mincost = 0;

	for(int i=0; i<m; ++i) {
		int u  = graph[i][0];
		int v  = graph[i][1];
		int wt = graph[i][2];

		if(find(u) != find(v)) {
			mincost += wt;
			unionn(u, v);
		}
	}
	cout << mincost << endl;
	return 0;
}