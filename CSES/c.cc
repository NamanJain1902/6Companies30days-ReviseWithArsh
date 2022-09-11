#include<bits/stdc++.h>
using namespace std;


const int MAX = 100000 + 5;
const int HMAX = 1000000007;

int n, m;
vector<vector<int>> graph, dist;
int binpower(int base, int power){
	int ans = 1;
	while(power>0){
		if(power%2)  
			ans = ans * base;
		base *= base;
		power /= 2;
	}
	return ans;
}

void floydWarshall() {

    dist.resize(n+1, vector<int>(n+1, -1));
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // checks for k intermediate nodes
    for(int k = 1; k <= n; ++k) {
        // take each node as start node
        for(int i=1; i<=n; ++i) {
            // and remaining nodes as destination node
            for(int j=1; j<=n; ++j) {
                if(i != j) { //
                    // if k is connected to both i and j
                    if(dist[i][k] != -1 and dist[k][j] != -1 ){ 
                        if(dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
                        else
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                } else {
                    dist[i][j] = 0;
                }
            } 
        }
    }

    long long int sum = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=i; j<=n; ++j) {
			sum += dist[i][j];
        }
    }

    string res;
    while(sum > 0) {
        int r = sum % 2;
        res += to_string(r);
        sum /= 2;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

void solve(){
    cin >> n >> m;

    graph.resize(n+1, vector<int>(n+1, -1));
    for(int i=0; i<m; ++i) {
        int a, b, wt;
        cin >> a >> b >> wt;
        graph[a][b] = binpower(2, wt);
        graph[b][a] = binpower(2, wt);
    }
    floydWarshall();

    
}

signed main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t=1;
  for(int i=1; i<=t; ++i){
    solve();
  }
}
